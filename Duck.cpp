#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class QuackBehavior {
public:
	virtual void quack() = 0;
};
class NoQuack : public QuackBehavior {
public:
	void quack() {
		printf("This duck can\'t speak!\n");
	}
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

class FlyBehavior {
public:
	virtual void fly() = 0;
};
class NoFly : public FlyBehavior {
public:
	void fly() {
		printf("This duck can\'t fly!\n");
	}
};
class NormalFly : public FlyBehavior {
public:
	void fly() {
		printf("Look! It is flying!\n");
	}
};

class Duck {
private:
	QuackBehavior* quackBehavior;
	FlyBehavior* flyBehavior;
public:
	Duck() : quackBehavior(new NoQuack()), flyBehavior(new NoFly()){}
	Duck(QuackBehavior* q) : quackBehavior(q), flyBehavior(new NoFly()){}
	Duck(FlyBehavior* f) : quackBehavior(new NoQuack()), flyBehavior(f){}
	Duck(QuackBehavior* q, FlyBehavior* f) : quackBehavior(q), flyBehavior(f){}
	void quack() {
		quackBehavior->quack();
	}
	void fly() {
		flyBehavior->fly();
	}
	void swim() {
		printf("Of course it can swim\n");
	}
	void print() {
		quack();
		swim();
		fly();
		printf("\n");
	}
};

int main() {
	Duck normalDuck(new NormalQuack());
	normalDuck.print();
	
	Duck rubberDuck(new SqueakQuack());
	rubberDuck.print();
	
	Duck decoyDuck;
	decoyDuck.print();
	
	Duck canFlyDuck(new NormalQuack(), new NormalFly());
	canFlyDuck.print();
	return 0;
}
