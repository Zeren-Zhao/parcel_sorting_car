#include <iostream>
#include <thread>
#include <queue>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void CaptureFrames(int camera_index, queue<Mat>& frame_queue, mutex& mtx, condition_variable& cv) {
    VideoCapture cap(camera_index);
    if (!cap.isOpened()) {
        cerr << "Failed to open the camera." << endl;
        return;
    }

    while (true) {
        Mat frame;
        cap >> frame;

        unique_lock<mutex> lock(mtx);
        frame_queue.push(frame);
        lock.unlock();

        cv.notify_one();
    }
}
