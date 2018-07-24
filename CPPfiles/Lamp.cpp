#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Lamp {
public:
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};
class DeskLamp : public Lamp {
	void turnOn() {
		printf("Turn On!\n");
	}
	void turnOff() {
		printf("Turn Off!\n");
	}
};
class Button {
private:
	Lamp* lamp;
public:
	Button(Lamp* l) : lamp(l){}
	void detect() {
		bool state = getState();
		if(state)	lamp->turnOn();
		else		lamp->turnOff();
	}
	virtual bool getState() = 0;
};
class PushButton : public Button {
public:
	PushButton(Lamp* l) : Button(l) {
		detect();
	}
	bool getState() {
		return true;
	}
};

int main() {
	DeskLamp deskLamp;
	PushButton pushButton(&deskLamp);
	
	return 0;
}
