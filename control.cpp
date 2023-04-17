#include <iostream>
#include <wiringPi.h>


using namespace std;

class L298N{
private:
    int in1, in2, in3, in4; //enA, enB
public:
    L298N(int in1_pin, int in2_pin, int in3_pin, int in4_pin){//int enA_pin, int enB_pin,
        //enA = enA_pin;
        //enB = enB_pin;
        in1 = in1_pin;
        in2 = in2_pin;
        in3 = in3_pin;
        in4 = in4_pin;
        //pinmode(enA, output);
        //pinmode(enB, output);
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);
    }

    void left(){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        //analogWrite(enA, 255);
        //analogwrite(enB, 255);
    }

    void forward(){
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }

    void retreat(){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }

    void right(){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    void stop(){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    }
    
};

