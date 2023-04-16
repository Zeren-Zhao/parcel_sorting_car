#include <iostream>
#include <queue>
#include <functional>
#include <zbar.h>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;
using namespace zbar;

class QRCodeScanner {
public:
    using Callback = std::function<void(const std::string&)>;

    QRCodeScanner(queue<Mat>& frame_queue) : frame_queue_(frame_queue) {}

    void DetectQR(const Callback& callback) {
        ImageScanner scanner;
        scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

        unordered_set<string> scanned_qrcodes;

        while (true) {
            if (!frame_queue_.empty()) {
                Mat frame = frame_queue_.front();
                frame_queue_.pop();

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

                        // Calling the callback function
                        callback(symbol->get_data());
                    }
                }

                image.set_data(nullptr, 0);
            }
        }
    }

private:
    queue<Mat>& frame_queue_;
};

