#include "SCUtilities.hpp"
#include <chrono>

double SCUtilities::getCurrentTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() / 1000.0;
}