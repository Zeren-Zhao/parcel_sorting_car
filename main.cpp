#include <iostream>
#include <string>
using namespace std;

class StateMachine {
public:

    void run(); // ����״̬��

    //���ⲿ����private�е�����
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2]){
        for (int i = 0; i < 2; i++) {
            car1[i] = car_pos1[i];
            car2[i] = car_pos2[i];
            car3[i] = car_pos3[i];
            source[i] = source_pos[i];
            currentState = SCAN;
        }
    };

private:
    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // ״̬����
    State currentState; // ��ǰ״̬


    int a = 0; // ����a
    int current_pos[2], goal_pos[2];//С��������λ���Լ�Ŀ��λ�ã�x, y��
    int car1[2], car2[2], car3[2];//����Ŀ�ĵص�λ�ã�x, y��
    int source[2];//ȡ������x, y��
    string location = "G12 0QA";

    void scanState(); // ɨ���ά��״̬
    void navigationState(); // ·���滮״̬
    void dischargeState(); // ж��״̬
    void decideState();//����״̬��Ŀ�ĵ����ģ�car1�� car2�� car3�� source��
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
    cout << "State: Scanning" << endl;
    a = 0;
    //DetectQR(); //���ü���ά��ĺ���
    currentState = DECIDE;
}

void StateMachine::dischargeState() {
    cout << "State: Unloading" << endl;
    a = 1;
    currentState = NAVIGATION; //�µ�״̬
}

void StateMachine::navigationState() {
    cout << "State: Navigation" << endl;
    cout << a << endl;
    if (a == 0){
        currentState = DISCHARGE;}
    else{
        currentState = SCAN;}
}

void StateMachine::decideState() {
    cout << "State: Decision" << endl;
    string information = location.substr(0, location.find(" "));

    if (a==1){
        for (int i = 0; i < 2; i++) {
            goal_pos[i] = source[i];
        }
        currentState = NAVIGATION;
    }
    else{

        if (information.compare("G1") == 0|information.compare("G2") == 0|information.compare("G3") == 0){
            cout << "Place A" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car1[i];
            }
            currentState = NAVIGATION;
        }
        else if (information.compare("G4") == 0|information.compare("G5") == 0|information.compare("G6") == 0){
                cout << "Place B" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car2[i];
            }
            currentState = NAVIGATION;
        }
        else if (information.compare("G12") == 0|information.compare("G13") == 0|information.compare("G67") == 0){
                cout << "Place C"<< endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car3[i];
            }
            currentState = NAVIGATION;
        }
        else{
            cout << "Wrong zip code" << endl;
            currentState = SCAN;
        }
    }
    cout << goal_pos[0] << endl;
    cout << goal_pos[1] << endl;
}


int main() {
    int source_pos[2], car_pos1[2], car_pos2[2], car_pos3[2];
    source_pos[0] = 0;
    source_pos[1] = 0;

    car_pos1[0] = 1;
    car_pos1[1] = 0;

    car_pos2[0] = 2;
    car_pos2[1] = 0;

    car_pos3[0] = 3;
    car_pos3[1] = 0;

    StateMachine sm(car_pos1, car_pos2, car_pos3, source_pos); // ʵ����״̬��car_pos1, car_pos2, car_pos3, source_pos
    sm.run(); // ����״̬��

    return 0;
}