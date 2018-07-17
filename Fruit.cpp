#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class BadFruitException {
public:
    string msg() {
        return "Stop Call Invalid Function!";
    }
};

class Plant {
private:
    string growPlace;
public:
    void setGrowPlace(string place) { growPlace = place; }
    string getGrowPlace() {return growPlace; }

	virtual void plant() = 0;
	virtual void grow() = 0;
	virtual void harvest() = 0;
    virtual void setWithSeed(bool is) {
        printf("Error : the plant do not support setWithSeed(bool) function\n");
        throw BadFruitException();
    }
	virtual bool isWithSeed() {
		printf("Error : the plant do not support isWithSeed() function\n");
		throw BadFruitException();
	}
	virtual int getAge() {
        printf("Error : the plant do not support getAge() function\n");
        throw BadFruitException();
	}
	virtual void setAge(int age) {
        printf("Error : the plant do not support setAge(int) function\n");
        throw BadFruitException();
	}
};

class Fruit : public Plant {
public:
    virtual void plant() = 0;
	virtual void grow() = 0;
	virtual void harvest() = 0;
};
class Grape : public Fruit {
private:
	bool withSeed;
public:
    bool isWithSeed() { return withSeed; }
    void setWithSeed(bool is) { withSeed = is; }
    void plant() { printf("Grape Plant\n"); }
	void grow() { printf("Grape Grow\n"); }
	void harvest() { printf("Grape Harvest\n"); }
};
class Strawberry : public Fruit {
    void plant() { printf("Strawberry Plant\n"); }
	void grow() { printf("Strawberry Grow\n"); }
	void harvest() { printf("Strawberry Harvest\n"); }
};
class Apple : public Fruit {
private:
	int age;
public:
    void setAge(int age) { this->age = age; }
    int getAge() { return age; }
    void plant() { printf("Apple Plant\n"); }
	void grow() { printf("Apple Grow\n"); }
	void harvest() { printf("Apple Harvest\n"); }
};

class Veggie : public Plant {
public:
    virtual void plant() = 0;
	virtual void grow() = 0;
	virtual void harvest() = 0;
};
class Cabbage : public Veggie {
    void plant() { printf("Cabbage Plant\n"); }
	void grow() { printf("Cabbage Grow\n"); }
	void harvest() { printf("Cabbage Harvest\n"); }
};
class Lettuce : public Veggie {
    void plant() { printf("Lettuce Plant\n"); }
	void grow() { printf("Lettuce Grow\n"); }
	void harvest() { printf("Lettuce Harvest\n"); }
};

class Gardener {
public:
    enum FruitType {grape, strawberry, apple};
    enum VeggieType {cabbage, lettuce};
    virtual Fruit& getFruit(FruitType ft) = 0;
    virtual Veggie& getVeggie(VeggieType vt) = 0;
};
class NorthernGardener : public Gardener {
public:
    Fruit& getFruit(FruitType ft) {
        Fruit* fruit;
        switch(ft) {
        case grape:
            fruit = new Grape();
            break;
        case strawberry:
            fruit = new Strawberry();
            break;
        case apple:
            fruit = new Apple();
            break;
        }
        fruit->setGrowPlace("Northern");
        return *fruit;
    }
    Veggie& getVeggie(VeggieType vt) {
        Veggie* veggie;
        switch(vt) {
        case cabbage:
            veggie = new Cabbage();
            break;
        case lettuce:
            veggie = new Lettuce();
            break;
        }
        veggie->setGrowPlace("Northern");
        return *veggie;
    }
};
class TropicalGardener : public Gardener {
public:
    Fruit& getFruit(FruitType ft) {
        Fruit* fruit;
        switch(ft) {
        case grape:
            fruit = new Grape();
            break;
        case strawberry:
            fruit = new Strawberry();
            break;
        case apple:
            fruit = new Apple();
            break;
        }
        fruit->setGrowPlace("Tropical");
        return *fruit;
    }
    Veggie& getVeggie(VeggieType vt) {
        Veggie* veggie;
        switch(vt) {
        case cabbage:
            veggie = new Cabbage();
            break;
        case lettuce:
            veggie = new Lettuce();
            break;
        }
        veggie->setGrowPlace("Tropical");
        return *veggie;
    }
};

void test(Plant& p) {
    printf("grow at : %s\n", p.getGrowPlace().c_str());
    p.plant();
    p.grow();
    p.harvest();
    try {
        p.setAge(1981);
        p.setWithSeed(true);
    }catch(BadFruitException e) {
        printf("%s\n", e.msg().c_str());
    }
    printf("\n");
}

int main() {
    NorthernGardener northernGardener;
    TropicalGardener tropicalGardener;

    Fruit& grape = northernGardener.getFruit(Gardener::grape);
    test(grape);

    Fruit& apple = tropicalGardener.getFruit(Gardener::apple);
    test(apple);

    Veggie& lettuce = northernGardener.getVeggie(Gardener::lettuce);
    test(lettuce);

    Veggie& cabbage = tropicalGardener.getVeggie(Gardener::cabbage);
    test(cabbage);

	return 0;
}
