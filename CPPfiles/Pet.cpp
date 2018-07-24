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
class Egg {
public:
	virtual Pet* hatch() = 0;
};
class DogEgg : public Egg {
public:
	Pet* hatch() { return new Dog(); }
};
class CatEgg : public Egg {
public:
	Pet* hatch() { return new Cat(); }
};
class  BirdEgg : public Egg {
public:
	Pet* hatch() { return new Bird(); }
};

class EggShop {
private:
	Egg* _egg;
public:
	EggShop(Egg* egg) : _egg(egg) {}
	Pet* hatch() { return _egg->hatch(); }
};

class People {
private:
	Pet* _pet;
public:
	void setPet(Pet* pet) {
		if(_pet != NULL)
			delete _pet;
		_pet = pet;
	}
	void callMyPet() {
		_pet->eat();
		_pet->sleep();
		_pet->walk();
        printf("\n");
	}
};

int main() {
	People me;
	EggShop dogmom(new DogEgg());
	me.setPet(dogmom.hatch());
	me.callMyPet();

	EggShop catmom(new CatEgg());
	me.setPet(catmom.hatch());
	me.callMyPet();

	EggShop birdmom(new BirdEgg());
	me.setPet(birdmom.hatch());
	me.callMyPet();

	return 0;
}
