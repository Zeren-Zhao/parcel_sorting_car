#include <iostream>
#include <fstream>
#include <unordered_set>
#include <zbar.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace zbar;

void DetectQR()
{
    // Open the camera
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Failed to open the camera." << endl;
        return;
    }
    
    namedWindow("QRCode Detector", cv::WINDOW_NORMAL);
    resizeWindow("QRCode Detector", 640, 480);

    // Create a zbar scanner
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

    // Create an unordered set to store scanned QR codes
    unordered_set<string> scanned_qrcodes;

    while (true) {
        // Capture a new frame from the camera
        Mat frame;
        cap >> frame;

        // Convert the frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Wrap the grayscale image data in a zbar image
        Image image(gray.cols, gray.rows, "Y800", (uchar*)gray.data, gray.cols * gray.rows);

        // Scan the zbar image for QR codes
        int n = scanner.scan(image);

        // Loop over all the detected QR codes
        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            // Check if the QR code has already been scanned
            if (scanned_qrcodes.find(symbol->get_data()) == scanned_qrcodes.end()) {
                // Print the QR code content
                cout << "Scanned QR code: " << symbol->get_data() << endl;

                // Save the QR code content to a file
                ofstream outfile("qrcode.txt", ios::app);
                outfile << symbol->get_data() << endl;
                outfile.close();

                // Add the scanned QR code to the set
                scanned_qrcodes.insert(symbol->get_data());
            }
        }

        imshow("QRCode Detector", frame);

        // Clean up
        image.set_data(nullptr, 0);
        if (waitKey(30) >= 0) {
            break;
        }
    }
}

