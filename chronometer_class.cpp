#include "chronometer_class.h"
#include <iomanip> // for std::setprecision()

void Chronometer::startTimer()
{
    start_ = std::chrono::steady_clock::now();
}

void Chronometer::stopTimer()
{
    end_ = std::chrono::steady_clock::now();
}

void Chronometer::printTimeElapsed()
{
    std::chrono::duration<double> diff = end_ - start_;
    // print only the first two significant decimal points
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << diff.count() << " seconds." << std::endl;
}