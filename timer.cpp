#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Stopwatch
{
public:
    Stopwatch() : m_isRunning(false), m_duration(0) {}

    void start()
    {
        m_isRunning = true;
        m_startTime = std::chrono::steady_clock::now();
        m_thread = std::thread(&Stopwatch::update, this);
    }

    void stop()
    {
        m_isRunning = false;
        m_thread.join();
        m_duration = std::chrono::duration_cast<std::chrono::milliseconds>(m_stopTime - m_startTime).count();
    }

    int getDuration()
    {
        return m_duration;
    }

private:
    void update()
    {
        while (m_isRunning)
        {
            m_stopTime = std::chrono::steady_clock::now();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::steady_clock::time_point m_stopTime;
    bool m_isRunning;
    int m_duration;
    std::thread m_thread;
};

void task1() {
    Stopwatch timer;
    timer.start();
    std::cout << "Task 1 started..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    timer.stop();
    std::cout << "Task 1 finished. Time taken: " << timer.getDuration()/1000 << " ms" << std::endl;
}

void task2() {
    Stopwatch timer;
    timer.start();
    std::cout << "Task 2 started..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    timer.stop();
    std::cout << "Task 2 finished. Time taken: " << timer.getDuration()/1000 << " ms" << std::endl;
}

int main() {
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();
    return 0;
}
