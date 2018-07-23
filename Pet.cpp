#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Pet {
public:
	virtual void eat() = 0;
	virtual void walk() = 0;
	virtual void sleep() = 0;
};
class Dog : public Pet {
public:
	void eat() { printf("dog eat\n"); }
	void walk() { printf("dog walk\n"); }
	void sleep() { printf("dog sleep\n"); }
};
class Cat : public Pet {
public:
	void eat() { printf("cat eat\n"); }
	void walk() { printf("cat walk\n"); }
	void sleep() { printf("cat sleep\n"); }
};
class Bird : public Pet {
public:
	void eat() { printf("bird eat\n"); }
	void walk() { printf("bird walk\n"); }
	void sleep() { printf("bird sleep\n"); }
};
class PetFactory {
public:
	enum PetType {
		DOG,
		CAT,
		BIRD
	};
	static Pet* create(PetType pt) {
		switch(pt) {
			case DOG:
				return new Dog();
			case CAT:
				return new Cat();
			case BIRD:
				return new Bird();
		}
	} 
};

int main() {
	Pet* doge = PetFactory::create(PetFactory::DOG);
	Pet* kitty = PetFactory::create(PetFactory::CAT);
	Pet* GG = PetFactory::create(PetFactory::BIRD);
	
	doge->eat();
	kitty->walk();
	GG->sleep();
	
	return 0;
}
