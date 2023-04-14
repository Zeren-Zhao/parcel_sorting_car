#include <iostream>
#include <thread>
#include <mutex>
#include "state_machine.cpp"
#include "QR.cpp"
#include <string>
int main() {

    int car_pos1[2] = {3, 4};
    int car_pos2[2] = {-3, 3};
    int car_pos3[2] = {2, 2};
    int source_pos[2] = {0, 0};

    //初始化变量
    string location = "";
    int current_1 = 0;
    int current_2 = 0;
    mutex mtx;

    /*class A {
    public:
        std::string scanQRCode() {
            // 扫描二维码并提取信息
            std::string info = "example QR code info";
            return info;
        }
    };*/

    QRCodeScanner detector(0);
    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    std::thread threadA([&]() {
        while(true){

            std::string info = detector.DetectQR();

            // 当car[2] == {1, 1}并且字符串loc == “”时赋给字符串loc
            if (current_1 == 0 && current_2 == 0 && location.empty()) {
                std::lock_guard<std::mutex> lock(mtx);
                location = info;
                cout << "cao" << endl;
        }}
    });

    std::thread threadB([&]() {
        // 只有在字符串loc！=“”时被唤醒
        while (true) {

            if (!location.empty()) {

                std::lock_guard<std::mutex> lock(mtx);

                machine.run();
            }
        }
    });

    // 等待线程A和线程B的完成
    threadA.join();
    threadB.join();

    return 0;
}