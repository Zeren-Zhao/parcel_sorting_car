//
// Created by apple on 2023/4/13.
//

#ifndef TEST2_QRCODESCANNER_H
#define TEST2_QRCODESCANNER_H

#pragma once

#include <string>

class QRCodeScanner {
public:
    QRCodeScanner(int camera_index = 0);
    std::string DetectQR();

private:
    int camera_index_;
};


#endif //TEST2_QRCODESCANNER_H
