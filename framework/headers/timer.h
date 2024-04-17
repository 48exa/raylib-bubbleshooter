#ifndef TIMER_H
#define TIMER_H

#include <raylib.h>

class Timer {
public:
  Timer() {
    _startTime = 0;
    _pausedTicks = 0;
    _paused = false;
    _started = false;
  };

  ~Timer();

  void start() {
    _startTime = GetTime();
    _started = true;
    _paused = false;
  };

  void stop() {
    _started = false;
    _paused = false;
  };

  double getSeconds() {
    if (_started)
      return GetTime() - _startTime;
    else {
      start();
      return GetTime() - _startTime;
    };
  };

  void restart() { start(); };

private:
  double _startTime;
  double _pausedTicks;
  bool _started;
  bool _paused;
};

#endif