#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Door;
class TimedDoor;
class Timer;
class TimerClient;

class Timer {
public:
	void regist(int timeOut, int timeOutId, TimerClient client) {
		client.timeOut(timeOutId);
	}
};
class TimerClient {
private:
	Timer timer;
public:
	TimeClient(Timer t) {
		timer = t;
	}
	void needNotify(int timeout, int timeOutId) {
		printf("Start the timer!\n");
		timer.regist(timeout, timeOutId, *this);
	}
	virtual void timeOut(int) = 0;
};

class Door {
private:
	bool isOpen;
public:
	Door() : isOpen(false){}
	void close() {
		if(!isOpen)
			printf("it\'s already close!\n");
		else
			isOpen = false;
	}
	void open() {
		if(isOpen)
			printf("it\' already open");
		else
			isOpen = true;
	}
	virtual void enter() = 0;
};
class TimedDoor : public Door {
private:
	TimerClient timerClient;
	int timerId;
	int timeout;
public:
	TimedDoor(int timeout) : Door() {
		this->timeout = timeout;
		timerId = 0;
	}
	void enter() {
		this->open();
		printf("Enter! Notify!\n");
		timerClient.needNotify(timeout, ++timeId);
	}
	void setAdapter(TimerClient timerClient) {
		this->timerClient = timerClient;
	}
	void doorTimeOut(int timeOutId) {
		close();
		printf("TimeOut! TimeOut!\n");
	}
};

class DoorTimerAdapter : TimerClient {
private:
	TimedDoor timedDoor;
public:
	DoorTimerAdapter(TimedDoor door, Timer timer) : TimerClient(timer) {
		timedDoor = door;
	}
	void timeOut(int timeOutId) {
		timedDoor.doorTimeOut(timeOutId);
	}
};

int main() {

	return 0;
}
