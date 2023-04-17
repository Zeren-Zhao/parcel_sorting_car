#ifndef QRCODESCANNER_H
#define QRCODESCANNER_H

#pragma once

#include <string>
#include <functional>

class QRCodeScanner {
public:
    QRCodeScanner(int camera_index = 0);
    
    void DetectQR(std::function<void(const std::string&)> callback);

private:
    int camera_index_;

};


#endif //QRCODESCANNER_H
