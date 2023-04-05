#include <iostream>
#include <string>
using namespace std;

class StateMachine {
public:
    StateMachine() { currentState = SCAN; } // 构造函数，初始状态
    void run(); // 运行状态机

private:
    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // 状态类型
    State currentState; // 当前状态
    int a = 0; // 参数a
    int car_pos[2], goal_pos[2];

    void scanState(); // 扫描二维码状态
    void navigationState(); // 路径规划状态
    void dischargeState(); // 卸货状态
    void decideState();
};

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
    cout << a << endl;
    if (a == 0){
        currentState = DISCHARGE;}
    else{
        currentState = SCAN;}   
}

void StateMachine::decideState() {
    cout << "当前状态：决定" << endl;
    currentState = NAVIGATION;
}

int main() {

    StateMachine sm; // 实例化状态机
    sm.run(); // 运行状态机

    return 0;
}
