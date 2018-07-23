#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class QuackBehavior {
public:
	virtual void quack() = 0;
};

class NormalQuack : public QuackBehavior {
public:
	void quack() {
		printf("said Quack! Quack!\n");
	}
};
class SqueakQuack : public QuackBehavior {
public:
	void quack() {
		printf("said Squeak! Squeak!\n");
	}
};

class SwimBehavior {
public:
	void swim() {
		printf("it can swim\n");
	}
};

class FlyBehavior {
public:
	virtual void fly() = 0;
};

class NormalFly : public FlyBehavior {
public:
	void fly() {
		printf("Look! It is flying!\n");
	}
};

class Duck {
private:
	QuackBehavior* _quack;
	SwimBehavior* _swim;
	FlyBehavior* _fly;
public:
	Duck() {
		_quack = NULL;
		_swim = NULL;
		_fly = NULL;
	}
	Duck& setQuack(QuackBehavior* qb) {
		_quack = qb;
	}
	Duck& setSwim(SwimBehavior* sb) {
		_swim = sb;
	}
	Duck& setFly(FlyBehavior* fb) {
		_fly = fb;
	}
	void quack() {
		if(_quack != NULL)
			_quack->quack();
	}
	void fly() {
		if(_fly != NULL)
			_fly->fly();
	}
	void swim() {
		if(_swim != NULL)
			_swim->swim();
	}
	void print() {
		quack();
		swim();
		fly();
		printf("\n");
	}
};

int main() {

	return 0;
}
