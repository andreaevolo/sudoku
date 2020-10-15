#include "Chronometer.h"
#include <iomanip> // for std::setprecision()

void Chronometer::startTimer() {
    start =  std::chrono::steady_clock::now();
}

void Chronometer::stopTimer() {
    end =  std::chrono::steady_clock::now();
}

void Chronometer::printTime() {
    std::chrono::duration<double> diff = end-start;
    // print only the first two significant decimal points
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout<<diff.count()<<" seconds.";
}