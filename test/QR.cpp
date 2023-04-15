#include <iostream>
#include <fstream>
#include <unordered_set>
#include <zbar.h>
#include <opencv2/opencv.hpp>



using namespace std;
using namespace cv;
using namespace zbar;

class QRCodeScanner {
public:
    using Callback = std::function<void(const std::string&)>;

    QRCodeScanner(int camera_index = 0) : camera_index_(camera_index) {}

    void DetectQR(const Callback& callback) {
        VideoCapture cap(camera_index_);
        if (!cap.isOpened()) {
            cerr << "Failed to open the camera." << endl;
            return;
        }

        namedWindow("QRCode Detector", cv::WINDOW_NORMAL);
        resizeWindow("QRCode Detector", 640, 480);

        ImageScanner scanner;
        scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

        unordered_set<string> scanned_qrcodes;

        while (true) {
            Mat frame;
            cap >> frame;

            Mat gray;
            cvtColor(frame, gray, COLOR_BGR2GRAY);

            Image image(gray.cols, gray.rows, "Y800", (uchar*)gray.data, gray.cols * gray.rows);

            int n = scanner.scan(image);

            for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
                if (scanned_qrcodes.find(symbol->get_data()) == scanned_qrcodes.end()) {
                    cout << "Scanned QR code: " << symbol->get_data() << endl;

                    ofstream outfile("qrcode.txt", ios::app);
                    outfile << symbol->get_data() << endl;
                    outfile.close();

                    scanned_qrcodes.insert(symbol->get_data());

                    // 调用回调函数
                    callback(symbol->get_data());
                    
                }
                
            }
            

            imshow("QRCode Detector", frame);

            image.set_data(nullptr, 0);
            if (waitKey(30) >= 0) {
                break;
            }
            
            
        }
    }

private:
    int camera_index_;
};
