#include <iostream>
#include <thread>
#include <string>
#include <mutex>

#include "state_machine.h"
#include "QRCodeScanner.h"

int main() {

    int car_pos1[2] = {1, 2};
    int car_pos2[2] = {3, 4};
    int car_pos3[2] = {5, 6};
    int source_pos[2] = {7, 8};

    //初始化变量
    std::string location = "";
    int current_1 = 1;
    int current_2 = 1;
    std::mutex mtx;

    QRCodeScanner detector(0);
    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    std::thread threadA([&]() {
        while(true){

            std::string info = detector.DetectQR();
            // 当car[2] == {1, 1}并且字符串loc == “”时赋给字符串loc
            if (current_1 == 1 && current_2 == 1 && location.empty()) {
                std::lock_guard<std::mutex> lock(mtx);
                location = info;
                cout << location << endl;

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