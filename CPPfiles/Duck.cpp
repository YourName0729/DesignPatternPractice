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
	virtual void swim() = 0;
};
class NormalSwim : public SwimBehavior {
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
	virtual void display() = 0;
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

class NormalDuck : public Duck {
public:
    void display() {
        printf("a normal duck\n");
    }
};
class RubberDuck : public Duck {
public:
    void display() {
        printf("a rubber duck\n");
    }
};
class DecoyDuck : public Duck {
public:
    void display() {
        printf("a decoy duck\n");
    }
};
class FlyDuck : public Duck {
public:
    void display() {
        printf("a fly duck\n");
    }
};

void test(Duck& d) {
    d.display();
    d.quack();
    d.swim();
    d.fly();
    printf("\n");
}

int main() {
    NormalDuck nd;
    nd.setQuack(new NormalQuack()).setSwim(new NormalSwim());
    test(nd);

    RubberDuck rd;
    rd.setQuack(new SqueakQuack()).setSwim(new NormalSwim());
    test(rd);

    DecoyDuck dd;
    dd.setSwim(new NormalSwim());
    test(dd);

    FlyDuck fd;
    fd.setQuack(new NormalQuack()).setFly(new NormalFly()).setSwim(new NormalSwim());
    test(fd);
	return 0;
}
