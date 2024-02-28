#include <timer.h>

Timer::Timer()
{
  _startTime = 0;
  _pausedTicks = 0;
  _paused = false;
  _started = false;
}

Timer::~Timer()
{
}

void Timer::start()
{
  _startTime = GetTime();
  _started = true;
  _paused = false;
}

void Timer::stop()
{
  _started = false;
  _paused = false;
}

double Timer::getSeconds()
{
  assert(_started); // You are trying to get the time from a timer that is disabled
  if (_started)
    return GetTime() - _startTime;
  else
    return -1.0;
}
