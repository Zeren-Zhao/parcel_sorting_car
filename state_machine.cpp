#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include "control.cpp"
#include <softPwm.h>
#include <functional>
#include "time.cpp"
#define PIN 15 
using namespace std;


int discharge()
{
    if (wiringPiSetup() == -1) {
        return 1;
    }

    softPwmCreate(PIN, 0, 100); 

    for (int i = 0; i <= 70; i++) {
        softPwmWrite(PIN, i);
        waittime(5); 
    }


    for (int i = 70; i >= 0; i--) {
        softPwmWrite(PIN, i);
        waittime(5); 
    }

    return 0;
}

class StateMachine {
public:

    void run(); // Run the state machine

    //Update the data in private from outside
    StateMachine(int car_pos1[2], int car_pos2[2], int car_pos3[2], int source_pos[2], int& current_1, int& current_2, string& location):current_1(current_1),current_2(current_2),location(location){
        for (int i = 0; i < 2; i++) {
            car1[i] = car_pos1[i];
            car2[i] = car_pos2[i];
            car3[i] = car_pos3[i];
            source[i] = source_pos[i];
            currentState = SCAN;
        }
    };

private:

    bool stopFlag = false;

    int& current_1;
    int& current_2;
    string& location;

    enum State { SCAN, NAVIGATION, DISCHARGE, DECIDE }; // Declare the state type
    State currentState; // Current state


    int a = 0; // Record the situation number 'a'
    int current_pos[2], goal_pos[2];//Current position & Goal position of the car
    int car1[2], car2[2], car3[2];//Coordinates of the three target locations
    int source[2];//取货处

    void scanState(); // Scan QR code state
    void navigationState(); // Path planning state
    void dischargeState(); // discharge state
    void decideState(); // decide state (where is the destination: car1, car2, car3, source)
};

void StateMachine::run() {
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

void StateMachine::scanState() {
    cout << "scan" << endl;
    a = 0;
    currentState = DECIDE;
}

void StateMachine::dischargeState() {
    cout << "discharge" << endl;
    discharge();
    a = 1;
    currentState = DECIDE; //Next state
}

void StateMachine::navigationState() {
    cout << "navigation" << endl;
    wiringPiSetup();
    L298N driver(26, 29, 27, 28);
    int x,y,turn;
    x = abs(goal_pos[0]-current_1)*500; // Set the time for x axis
    y = abs(goal_pos[1]-current_2)*500; // Set the time for y axis
    turn = 520;                         //The time for the car turning 90°
    
    std::function<void()> stop_callback = [&driver](){
        driver.stop();
        };
    //Compare the coordinate relationship between the initial point and the target point for y axis
    if(current_2 >= goal_pos[1]) {
        current_2 = goal_pos[1];       
        driver.retreat();
        wait_time(y, stop_callback);

    }
    else{
        current_2 = goal_pos[1];
        driver.forward();
        wait_time(y, stop_callback);

    }
    //Compare the coordinate relationship between the initial point and the target point for x axis
    if(current_1 >= goal_pos[0]) {
        current_1 = goal_pos[0];
        driver.left();
        wait_time(turn, stop_callback);

        driver.forward();
        wait_time(x, stop_callback);

        driver.right();
        wait_time(turn, stop_callback);

    }
    else {
        current_1 = goal_pos[0];
        driver.right();
        wait_time(turn, stop_callback);
        
        driver.forward();
        wait_time(x, stop_callback);
        
        driver.left();
        wait_time(turn, stop_callback);

    }

    if (a == 0){
        currentState = DISCHARGE;}
    else{
        location = "";
        stopFlag = true;
        currentState = SCAN;}
}

void StateMachine::decideState() {
    cout << "decision" << endl;
    string information = location.substr(0, location.find(" ")); //Extract the area code before the space

    if (a==1){
        for (int i = 0; i < 2; i++) {
            goal_pos[i] = source[i];   // Update destination coordinates to initial position
        }
        currentState = NAVIGATION;
    }
    else{

        if (information.compare("G1") == 0|information.compare("G2") == 0|information.compare("G3") == 0){
            cout << "Place A" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car1[i];    // Update destination coordinates to zone 1
            }
            currentState = NAVIGATION;
        }
        else if (information.compare("G4") == 0|information.compare("G5") == 0|information.compare("G6") == 0){
            cout << "Place B" << endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car2[i];   // Update destination coordinates to zone 2
            }

            currentState = NAVIGATION;
        }
        else if (information.compare("G12") == 0|information.compare("G13") == 0|information.compare("G67") == 0){
            cout << "Place C"<< endl;
            for (int i = 0; i < 2; i++) {
                goal_pos[i] = car3[i];    // Update destination coordinates to zone 3
            }
            currentState = NAVIGATION;
        }
        else{
            cout << "Wrong zip code" << endl;
            location.clear();
            stopFlag = true;
            currentState = SCAN;
        }
    }
}
