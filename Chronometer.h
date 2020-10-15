#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include <chrono>
#include <iostream>
class Chronometer {
  std::chrono::time_point<std::chrono::steady_clock> start;
  std::chrono::time_point<std::chrono::steady_clock> end;
  public:
  Chronometer() {}

  void startTimer();
  void stopTimer();
  
  void printTime();
};

#endif