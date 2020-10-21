#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <chrono>
#include <iostream>
#include <iomanip> // for std::setprecision()
class Chronometer
{
  std::chrono::time_point<std::chrono::steady_clock> start_;
  std::chrono::time_point<std::chrono::steady_clock> end_;

public:
  Chronometer() {}

  void startTimer();
  void stopTimer();
  void printTimeElapsed();
};

#endif