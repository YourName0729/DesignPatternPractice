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
	void regist(int timeOut, int timeOutId, TimerClient* client);
};
class TimerClient {
private:
	Timer timer;
public:
	TimerClient(Timer t) : timer(t){}
	void needNotify(int timeout, int timeOutId) {
		printf("[TimerClient] Start the timer!\n");
		timer.regist(timeout, timeOutId, this);
	}
	virtual void timeOut(int) = 0;
};

void Timer::regist(int timeOut, int timeOutId, TimerClient* client) {
	printf("[Timer] get and time out\n");
	client->timeOut(timeOutId);
}

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
	TimerClient* timerClient;
	int timerId;
	int timeout;
public:
	TimedDoor() {}
	TimedDoor(int timeout) : Door() {
		this->timeout = timeout;
		timerId = 0;
	}
	void enter() {
		this->open();
		printf("[TimedDoor] Enter! Notify!\n");
		timerClient->needNotify(timeout, ++timerId);
	}
	void setAdapter(TimerClient* timerClient) {
		this->timerClient = timerClient;
	}
	void doorTimeOut(int timeOutId) {
		printf("[TimedDoor] time out? close the door!\n");
		close();
		printf("END\n");
	}
};

class DoorTimerAdapter : public TimerClient {
private:
	TimedDoor timedDoor;
public:
	DoorTimerAdapter(TimedDoor door, Timer timer) : TimerClient(timer) {
		timedDoor = door;
	}
	void timeOut(int timeOutId) {
		printf("[DoorTimerAdapter] call back to the Door\n");
		timedDoor.doorTimeOut(timeOutId);
	}
};

int main() {
	int timeout = 5;
	Timer timer;
	TimedDoor timedDoor(timeout);
	DoorTimerAdapter dTA(timedDoor, timer);
	timedDoor.setAdapter(&dTA);
	timedDoor.enter();
	/*public static void main(String[] args) {
        int timeout = 5;
        Timer timer = new Timer();	
        TimedDoor timedDoor = new TimedDoor(timeout);
        TimerClient dTA = new DoorTimerAdapter(timedDoor, timer);
        timedDoor.setAdapter(dTA);
        System.out.println("Is door open: "+timedDoor.isDoorOpen());
        timedDoor.enter();
        System.out.println("Is door open: "+timedDoor.isDoorOpen());
    }*/
	return 0;
}
