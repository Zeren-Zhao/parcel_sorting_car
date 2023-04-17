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

    //Initialize variables
    string location = "";
    int current_1 = 0;
    int current_2 = 0;
    mutex mtx;

    QRCodeScanner detector(0);
    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    auto callback = [&](const std::string& info) {
        if (current_1 == 0 && current_2 == 0 && location.empty()) {
            location = info;
            machine.run();
        }
    };

    /*We use polling here to detect the QR code, which is necessary because this is a
    real-time detection program that constantly detects the presence of a QR code from the video
    stream returned by the camera, and the event triggering after the detection of the QR code is implemented through the callback function*/
    while (true) {
        detector.DetectQR(callback);
    }



    return 0;
}
