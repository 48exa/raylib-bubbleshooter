// timer.cpp

#include "timer.h"

Timer::Timer()
{
  _started = true;
}

Timer::~Timer()
{
  delete this;
}

void Timer::update(float deltaTime)
{
  if (_started)
  {
    _time += 1 * deltaTime;
  }
}

void Timer::start()
{
  this->_started = true;
}

void Timer::reset()
{
  this->_time = 0;
}

int Timer::time()
{
  return (int)this->_time;
}

void Timer::stop()
{
  this->_started = 0;
}