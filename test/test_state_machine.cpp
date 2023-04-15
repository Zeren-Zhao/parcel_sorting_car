#include <iostream>
#include <thread>
#include <mutex>
#include "state_machine.cpp"
#include <string>
int main() {

    int car_pos1[2] = {3, 4};
    int car_pos2[2] = {-3, 3};
    int car_pos3[2] = {1, 1};
    int source_pos[2] = {0, 0};

    //初始化变量
    string location = "G12 8bb";
    int current_1 = 0;
    int current_2 = 0;

    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    machine.run();
                
    cout << "current_1 is : " << current_1 << endl;
    cout << "current_2 is : " << current_2 << endl;
    cout << "location is :" << location << endl;



    // 等待线程A和线程B的完成

    return 0;
}
