#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Beverage {
	
}; 
class MilkTea : public Beverage {
	
};
class Coffee : public Beverage {
	
};

class Builder {
public:
	virtual Beverage& build() = 0;
	virtual void brew() = 0;
	virtual void flavor() = 0;
	virtual void mix() = 0;
};
class MilkTeaBuilder : public Builder {
public:
	void brew() {
		printf("brew with black tea\n");
	}
	void flavor() {
		printf("add milk\n");
	}
	void mix() {
		printf("mix with chocolate\n");
	}
	Beverage& build() {
		MilkTea mt;
		brew();
		flavor();
		mix();
		return mt;
	}
};
class CoffeeBuilder : public Builder {
public:
	void brew() {
		printf("milling\n");
	}
	void flavor() {
		printf("add creamer\n");
	}
	void mix() {
		printf("mix with cinnamon powder\n");
	}
	Beverage& build() {
		Coffee cf;
		brew();
		flavor();
		mix();
		return cf;
	}
};
class BuilderDirector {
private:
	Builder* builder;
public:
	enum BuilderType {
		milkTeaB,
		coffeeB
	};
	BuilderDirector(BuilderType bt) {
		switch(bt) {
			case milkTeaB:
				builder = new MilkTeaBuilder();
				break;
			case coffeeB:
				builder = new CoffeeBuilder();
				break;
		}
	}
	Beverage& build() {
		return builder->build();
	}
};

int main() {
	BuilderDirector builderDirector1(BuilderDirector::milkTeaB);
	Beverage milkTea = builderDirector1.build();
	printf("\n");
	
	BuilderDirector builderDirector2(BuilderDirector::coffeeB);
	Beverage coffee = builderDirector2.build();
	
	return 0;
}
