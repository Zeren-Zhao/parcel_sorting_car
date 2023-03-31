#include <wiringPi.h>

#define IN1 5
#define IN2 6
#define IN3 13
#define IN4 19

int main()
{
    // 初始化WiringPi库
    wiringPiSetup();

    // 配置GPIO引脚为输出模式
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // 设置电机方向和速度
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    // 延时一段时间
    delay(1000);

    // 停止电机
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    return 0;
}
