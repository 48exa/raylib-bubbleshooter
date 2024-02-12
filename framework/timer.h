// timer.h

#ifndef TIMER_H
#define TIMER_H

#include "raylib.h"

class Timer
{
public:
	Timer();
	virtual ~Timer();
	void start();
	void reset();
	int time();
	void stop();
	void update(float deltaTime);

private:
	float _time;
	bool _started;
};

#endif /* TIMER_H */
