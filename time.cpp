#include <iostream>
#include <chrono>
#include <cstdlib>
#include <functional>

void wait_time(unsigned int milliseconds, std::function<void()> callback)
{
    fd_set fds;
    struct timeval timeout;
    int ret;

    // Create an empty set of file descriptors
    FD_ZERO(&fds);

    // Set the overtime be 1s
    timeout.tv_sec = 0;
    timeout.tv_usec = milliseconds*1000;

    // Wait for timeout or file descriptor to become readable
    ret = select(0, NULL, NULL, &fds, &timeout);
    callback();

}

void waittime(unsigned int milliseconds)
{
    fd_set fds;
    struct timeval timeout;
    int ret;

    // Create an empty set of file descriptors
    FD_ZERO(&fds);

    // Set the overtime be 1s
    timeout.tv_sec = 0;
    timeout.tv_usec = milliseconds*1000;

    // Wait for timeout or file descriptor to become readable
    ret = select(0, NULL, NULL, &fds, &timeout);
}
