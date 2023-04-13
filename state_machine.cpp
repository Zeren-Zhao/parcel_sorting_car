#include "state_machine.h"

StateMachine::StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2], int& current_1, int& current_2, string& location):current_1(current_1),current_2(current_2),location(location){
    for (int i = 0; i < 2; i++) {
        car1[i] = car_pos1[i];
        car2[i] = car_pos2[i];
        car3[i] = car_pos3[i];
        source[i] = source_pos[i];
        currentState = SCAN;
    }
}


void StateMachine::run() {
    // run函数实现
    stopFlag = false;
    while (!stopFlag) {
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

void StateMachine::navigationState() {
    // navigationState函数实现
    cout << "navigation" << endl;
    if (a == 0){
        currentState = DISCHARGE;}
    else{
        current_1 = 1;
        current_2 = 1;
        location = "";
        stopFlag = true;
        currentState = SCAN;
    }
}

void StateMachine::scanState() {
    // scanState函数实现
    cout << "scan" << endl;
    a = 0;
    currentState = DECIDE;
}

void StateMachine::dischargeState() {
    // dischargeState函数实现
    cout << "discharge" << endl;
    a = 1;
    currentState = NAVIGATION; //新的状态
}

void StateMachine::decideState() {
    // decideState函数实现
    cout << "decision" << endl;
    current_1 = 2;
    current_2 = 2;
    if (a==1){
        for (int i = 0; i < 2; i++) {
            goal_pos[i] = source[i];
        }
    }
    else{
        for (int i = 0; i < 2; i++) {
            goal_pos[i] = car1[i];
        }
    }
    currentState = NAVIGATION;
    if (currentState == DISCHARGE) {
        stopFlag = true;
    }
}
