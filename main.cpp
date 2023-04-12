#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include "QR.cpp"

int main() {
    QRCodeScanner detector(0);

    // 创建线程
    std::thread t([&]() {
        while (true) {

            std::string result = detector.DetectQR();
            // 如果检测到QR码，可以在这里做一些其他的处理

        }
    });

    std::thread t1([&]() {
        while (true) {

            std::string result = detector.DetectQR();
            // 如果检测到QR码，可以在这里做一些其他的处理

        }
    });
    // 主线程执行其他任务


    // 等待线程结束
    t.join();
    t1.join();

    return 0;
}