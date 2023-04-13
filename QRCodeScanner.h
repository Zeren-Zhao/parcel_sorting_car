#ifndef QRCODESCANNER_H
#define QRCODESCANNER_H

#pragma once

#include <string>

class QRCodeScanner {
public:
    QRCodeScanner(int camera_index = 0);
    std::string DetectQR();

private:
    int camera_index_;
};


#endif //QRCODESCANNER_H
