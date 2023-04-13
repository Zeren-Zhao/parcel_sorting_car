//
// Created by apple on 2023/4/13.
//

#ifndef TEST2_STATE_MACHINE_H
#define TEST2_STATE_MACHINE_H

#include <iostream>
#include <string>

using namespace std;

class StateMachine {
public:
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2], int& current_1, int& current_2, string& location);
    void run(); // 运行状态机

private:
    bool stopFlag;
    int& current_1;
    int& current_2;
    string& location;
    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // 状态类型
    State currentState; // 当前状态
    int a; // 参数a
    int current_pos[2], goal_pos[2];//小车的现在位置以及目标位置
    int car1[2], car2[2], car3[2];//三个目的地的位置
    int source[2];//取货处
    void scanState(); // 扫描二维码状态
    void navigationState(); // 路径规划状态
    void dischargeState(); // 卸货状态
    void decideState();//决定状态（目的地是哪：car1， car2， car3， source）
};


#endif //TEST2_STATE_MACHINE_H
