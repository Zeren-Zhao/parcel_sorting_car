#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <unordered_set>
#include <zbar.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace zbar;

class StateMachine {
public:

    void run(); // 运行状态机

    //从外部更新private中的数据
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2]){
        for (int i = 0; i < 2; i++) {
            car1[i] = car_pos1[i];
            car2[i] = car_pos2[i];
            car3[i] = car_pos3[i];
            source[i] = source_pos[i];
            currentState = SCAN;
        }
    };

private:
    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // 状态类型
    State currentState; // 当前状态


    int a = 0; // 参数a
    int current_pos[2], goal_pos[2];//小车的现在位置以及目标位置（x, y）
    int car1[2], car2[2], car3[2];//三个目的地的位置（x, y）
    int source[2];//取货处（x, y）
    string location = "G12 0QA";

    void scanState(); // 扫描二维码状态
    void navigationState(); // 路径规划状态
    void dischargeState(); // 卸货状态
    void decideState();//决定状态（目的地是哪：car1， car2， car3， source）
};

int move(){
    Sleep(1000);
    cout << "1 STEP" << endl;
    return 0;
}

int turn(){
    cout << "Turning" << endl;
    Sleep(1000);
    return 0;
}

string DetectQR()
{
    // Open the camera
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Failed to open the camera." << endl;
        return "";
    }

    namedWindow("QRCode Detector", cv::WINDOW_NORMAL);
    resizeWindow("QRCode Detector", 640, 480);

    // Create a zbar scanner
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    // Create an unordered set to store scanned QR codes
    unordered_set<string> scanned_qrcodes;

    while (true) {
        // Capture a new frame from the camera
        Mat frame;
        cap >> frame;

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Wrap the grayscale image data in a zbar image
        Image image(gray.cols, gray.rows, "Y800", (uchar*)gray.data, gray.cols * gray.rows);

        // Scan the zbar image for QR codes
        int n = scanner.scan(image);

        // Loop over all the detected QR codes
        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            // Check if the QR code has already been scanned
            if (scanned_qrcodes.find(symbol->get_data()) == scanned_qrcodes.end()) {
                // Print the QR code content
                cout << "Scanned QR code: " << symbol->get_data() << endl;

                // Save the QR code content to a file
                ofstream outfile("qrcode.txt", ios::app);
                outfile << symbol->get_data() << endl;
                outfile.close();

                // Add the scanned QR code to the set
                scanned_qrcodes.insert(symbol->get_data());
                return symbol->get_data();//Return the scanned QR code content
            }
        }

        imshow("QRCode Detector", frame);

        // Clean up
        image.set_data(nullptr, 0);
        if (waitKey(30) >= 0) {
            break;
        }
    }
    return "";//Return empty string if no QR code is scanned
}

void StateMachine::run() {
    while (true) {
        switch (currentState) {
            case SCAN:
                scanState();
                break;
            case NAVIGATION:
                navigationState();
                break;
            case DISCHARGE:
                dischargeState();
                break;
            case DECIDE:
                decideState();
                break;
        }
    }
}

void StateMachine::scanState() {
    cout << "State: Scanning" << endl;
    a = 0;
    DetectQR(); //调用检测二维码的函数
    currentState = DECIDE;
}

void StateMachine::dischargeState() {
    cout << "State: Unloading" << endl;
    a = 1;
    current_pos[0] = goal_pos[0];
    current_pos[1] = goal_pos[1];
    currentState = NAVIGATION; //新的状态
}

void StateMachine::navigationState() {
    double start, stop, duration;
    int x,y;
    x = goal_pos[0];
    y = goal_pos[1];
    cout << "State: Navigation" << endl;
    cout << a << endl;
    cout << x << endl;
    cout << y << endl;
    start = clock();
    if (a == 0){
        for(int i = 0;i < y; i++){
            move();
        }
        turn();
        for(int i = 0;i < x; i++){
            move();
        }
        turn();
        stop = clock();
        duration = ((double)(stop - start))/CLK_TCK;
        cout << "Time cost:"<< duration << endl << endl;
        currentState = DISCHARGE;}
    else{
        currentState = SCAN;}
}

void StateMachine::decideState() {
    cout << "State: Decision" << endl;
    string information = location.substr(0, location.find(" "));

    if (a==1){
        for (int i = 0; i < 2; i++) {
            goal_pos[i] = source[i];
        }
        currentState = NAVIGATION;
    }
    else{

        if (information.compare("G1") == 0|information.compare("G2") == 0|information.compare("G3") == 0){
            cout << "Place A" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car1[i];
            }
            currentState = NAVIGATION;
        }
        else if (information.compare("G4") == 0|information.compare("G5") == 0|information.compare("G6") == 0){
                cout << "Place B" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car2[i];
            }
            currentState = NAVIGATION;
        }
        else if (information.compare("G12") == 0|information.compare("G13") == 0|information.compare("G67") == 0){
                cout << "Place C"<< endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car3[i];
            }
            currentState = NAVIGATION;
        }
        else{
            cout << "Wrong zip code" << endl;
            currentState = SCAN;
        }
    }
    cout << goal_pos[0] << endl;
    cout << goal_pos[1] << endl;
}


int main() {
    int source_pos[2], car_pos1[2], car_pos2[2], car_pos3[2];
    source_pos[0] = 0;
    source_pos[1] = 0;

    car_pos1[0] = 1;
    car_pos1[1] = 0;

    car_pos2[0] = 2;
    car_pos2[1] = 0;

    car_pos3[0] = 3;
    car_pos3[1] = 0;

    StateMachine sm(car_pos1, car_pos2, car_pos3, source_pos); // 实例化状态机car_pos1, car_pos2, car_pos3, source_pos
    sm.run(); // 运行状态机

    return 0;
}

