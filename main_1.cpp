#include <iostream>
#include <thread>
#include "state_machine.cpp"




int main() {

    int car_pos1[2] = {1, 2};
    int car_pos2[2] = {3, 4};
    int car_pos3[2] = {5, 6};
    int source_pos[2] = {7, 8};

    string location = "1111";
    int current_1 = 2;
    int current_2 = 2;

    StateMachine machine(car_pos1, car_pos2, car_pos3, source_pos, current_1, current_2, location);

    // 创建一个新的线程来运行状态机
    std::thread t(&StateMachine::run, &machine);

    // 等待状态机线程结束
    t.join();

    return 0;
}
