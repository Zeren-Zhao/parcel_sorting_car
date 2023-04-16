#include <iostream>
#include <thread>
#include <queue>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

queue<Mat> frame_queue;

void CaptureFrames(int camera_index) {
    VideoCapture cap(camera_index);
    if (!cap.isOpened()) {
        cerr << "Failed to open the camera." << endl;
        return;
    }

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        frame_queue.push(frame);
    }
}
