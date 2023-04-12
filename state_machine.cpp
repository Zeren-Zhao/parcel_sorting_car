#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class StateMachine {
public:

    void run(); // 运行状态机

    //从外部更新private中的数据
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2], int& current_1, int& current_2, string& location):current_1(current_1),current_2(current_2),location(location){
        for (int i = 0; i < 2; i++) {
            car1[i] = car_pos1[i];
            car2[i] = car_pos2[2];
            car3[i] = car_pos3[2];
            source[i] = source_pos[i];
            currentState = SCAN;
        }
    };

private:

    bool stopFlag = false;

    int& current_1;
    int& current_2;
    string& location;

    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // 状态类型
    State currentState; // 当前状态


    int a = 0; // 参数a
    int current_pos[2], goal_pos[2];//小车的现在位置以及目标位置
    int car1[2], car2[2], car3[2];//三个目的地的位置
    int source[2];//取货处

    void scanState(); // 扫描二维码状态
    void navigationState(); // 路径规划状态
    void dischargeState(); // 卸货状态
    void decideState();//决定状态（目的地是哪：car1， car2， car3， source）
};

void StateMachine::run() {
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

void StateMachine::scanState() {
    cout << "当前状态：扫描二维码" << endl;
    a = 0;
    currentState = DECIDE;
}

void StateMachine::dischargeState() {
    cout << "当前状态：卸货" << endl;
    a = 1;
    currentState = NAVIGATION; //新的状态
}

void StateMachine::navigationState() {
    cout << "当前状态：导航" << endl;
    if (a == 0){
        currentState = DISCHARGE;}
    else{
        current_1 = 0;
        current_2 = 0;
        location = "";
        stopFlag = true;
        currentState = SCAN;}   
}

void StateMachine::decideState() {
    cout << "当前状态：决定" << endl;
    current_1 = 1;
    current_2 = 1;
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
}


