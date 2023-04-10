#include <wiringPi.h>
#include <iostream>

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
        
        void turnleft(){
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
            //analogWrite(enA, 255);
            //analogwrite(enB, 255);
        }
        
        void straight(){
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
        }
        
        void turnRight(){
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
        }
};

int main(){
    
    wiringPiSetup();
    L298N driver(26, 29, 27, 28);
    
    driver.turnleft();
    delay(1000);

    
    std::cout <<"hello" << std::endl;
    return 0;
}
