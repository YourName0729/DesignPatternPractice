#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Beverage {
private:	
	string brew;
	string flavor;
	string mix;
public:
	class Builder;
	Beverage(){}
	Beverage(string b, string f, string m) : brew(b), flavor(f), mix(m){}
	void print() {
		printf("brew with %s\n", brew.c_str());
		printf("add %s for flavor\n", flavor.c_str());
		printf("mix with %s\n\n", mix.c_str());
	}
};

class Beverage::Builder {
private:
	string brew;
	string flavor;
	string mix;
public:
	Builder(){}
	Builder(string b, string f, string m) : brew(b), flavor(f), mix(m){}
	Builder& setBrew(string b){
		brew = b;
		return *this;
	}
	Builder& setFlavor(string f){
		flavor = f;
		return *this;
	}
	Builder& setMix(string m){
		mix = m;
		return *this;
	}
	Builder& setMilkTea(){
		brew = "Black Tea";
		flavor = "Milk";
		mix = "Chocolate Powder";
		return *this;
	}
	Builder& setCoffee(){
		brew = "Coffee Beans";
		flavor = "Creamer";
		mix = "Cinnamon Powder";
		return *this;
	}
	Beverage build() {
		return Beverage(brew, flavor, mix);
	}
};
/*class MilkTea : public Beverage {
public:
	void brew(){
		printf("brew black tea\n");
	}
	void flavor(){
		printf("add milk\n");
	}
	void mix() {
		printf("add chocolate\n");
	}
};

class Coffee : public Beverage {
public:
	void brew(){
		printf("brew coffee beans\n");
	}
	void flavor(){
		printf("add creamer\n");
	}
	void mix() {
		printf("add Cinnamon powder\n");
	}
};*/

int main() {
//Way1
	//MilkTea
	Beverage milkTea = Beverage::Builder().setMilkTea().build();
	milkTea.print();
	//Coffee
	Beverage coffee = Beverage::Builder().setCoffee().build();
	coffee.print();
//Way2
	Beverage milkTea2 = Beverage::Builder()
						.setBrew("Black Tea")
						.setFlavor("Milk")
						.setMix("Chocolate Powder")
						.build();
	milkTea2.print();
//Way3
	Beverage::Builder b;
	b.setCoffee();
	Beverage coffee2 = b.build();
	coffee2.print();
	return 0;
}
