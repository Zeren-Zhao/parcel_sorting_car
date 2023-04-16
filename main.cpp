#include <iostream>
#include <thread>
#include <mutex>
#include "state_machine.cpp"
#include "QR.cpp"
#include <string>
#include "camera.cpp"

int main() {

    int camera_index = 0;
    
    int car_pos1[2] = {3, 4};
    int car_pos2[2] = {-3, 3};
    int car_pos3[2] = {2, 2};
    int source_pos[2] = {0, 0};

    //Initialize variables
    string location = "";
    int current_1 = 0;
    int current_2 = 0;
    mutex mtx;
    
    QRCodeScanner scanner;

    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    auto callback = [&](const std::string& info) {
        if (current_1 == 0 && current_2 == 0 && location.empty()) {
            location = info;
            machine.run();
        }
    };


    thread capture_thread(CaptureFrames, camera_index);
    thread detection_thread(&QRCodeScanner::DetectQR, &scanner, callback);

    capture_thread.join();
    detection_thread.join();


    return 0;
}

