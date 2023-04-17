#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <wiringPi.h>

class L298N{
private:
    int in1, in2, in3, in4; 
public:
    L298N(int in1_pin, int in2_pin, int in3_pin, int in4_pin);
    void left();
    void forward();
    void retreat();
    void right();
    void stop();
};

#endif //CONTROL_H
