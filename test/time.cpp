#include <iostream>
#include <chrono>
#include <cstdlib>
#include <functional>

void wait_time(unsigned int milliseconds, std::function<void()> callback)
{
    fd_set fds;
    struct timeval timeout;
    int ret;

    // 创建一个空的文件描述符集合
    FD_ZERO(&fds);

    // 设置超时时间为1秒
    timeout.tv_sec = 0;
    timeout.tv_usec = milliseconds*1000;

    // 等待超时或文件描述符变为可读
    ret = select(0, NULL, NULL, &fds, &timeout);
    callback();

}

void waittime(unsigned int milliseconds)
{
    fd_set fds;
    struct timeval timeout;
    int ret;

    // 创建一个空的文件描述符集合
    FD_ZERO(&fds);

    // 设置超时时间为1秒
    timeout.tv_sec = 0;
    timeout.tv_usec = milliseconds*1000;

    // 等待超时或文件描述符变为可读
    ret = select(0, NULL, NULL, &fds, &timeout);
}
