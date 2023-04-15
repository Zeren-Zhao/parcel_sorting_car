#include <iostream>
#include <thread>
#include "QR.cpp"
#include <string>
int main() {


    //初始化变量
    string location = "";
    int current_1 = 0;
    int current_2 = 0;



    QRCodeScanner detector(0);
    
    auto callback = [&](const std::string& info) {
        if (current_1 == 0 && current_2 == 0 && location.empty()) {
            location = info;
        }
    };


    detector.DetectQR(callback);

    return 0;
}
