#include <iostream>
#include <string>
using namespace std;

class StateMachine {
public:

    void run(); // 运行状态机

    //从外部更新private中的数据
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2]){
        for (int i = 0; i < 2; i++) {
            car1[i] = car_pos1[i];
            car2[i] = car_pos2[2];
            car3[i] = car_pos3[2];
            source[i] = source_pos[i];
            currentState = SCAN;
        }
    };

private:
    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // 状态类型
    State currentState; // 当前状态


    int a = 0; // 参数a
    int current_pos[2], goal_pos[2];//小车的现在位置以及目标位置（x, y）
    int car1[2], car2[2], car3[2];//三个目的地的位置（x, y）
    int source[2];//取货处（x, y）

    void scanState(); // 扫描二维码状态
    void navigationState(); // 路径规划状态
    void dischargeState(); // 卸货状态
    void decideState();//决定状态（目的地是哪：car1， car2， car3， source）
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
    DetectQR(); //调用检测二维码的函数
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
    cout << goal_pos[1] << endl;
    currentState = NAVIGATION;
}

int main() {
    int source_pos[2], car_pos1[2], car_pos2[2], car_pos3[2];
    source_pos[0] = 5;
    source_pos[1] = 1;
    car_pos1[0] = 10;
    car_pos1[1] = 10;
    car_pos2[0] = 5;
    car_pos2[1] = 10;
    car_pos3[0] = 0;
    car_pos3[1] = 10;

    StateMachine sm(car_pos1, car_pos2, car_pos3, source_pos); // 实例化状态机car_pos1, car_pos2, car_pos3, source_pos
    sm.run(); // 运行状态机

    return 0;
}
