#pragma once
#include <functional>

void wait_time(unsigned int milliseconds, std::function<void()> callback);
void waittime(unsigned int milliseconds);
