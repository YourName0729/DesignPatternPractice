#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Fruit {
public:
    virtual void grow() = 0;
    virtual void plant() = 0;
    virtual void harvest() = 0;
};
class NorthernFruit : public Fruit {
public:
    void grow() { printf("northern fruit grow\n"); }
    void plant() { printf("northern fruit plant\n"); }
    void harvest() { printf("northern fruit harvest\n"); }
};
class TropicalFruit : public Fruit {
public:
    void grow() { printf("tropical fruit grow\n"); }
    void plant() { printf("tropical fruit plant\n"); }
    void harvest() { printf("tropical fruit harvest\n"); }
};

class Veggie {
public:
    void grow() = 0;
    void plant() = 0;
    void harvest() = 0;
};
class NorthernVeggie : public Veggie {
public:
    void grow() { printf("northern veggie grow\n"); }
    void plant() { printf("northern veggie plant\n"); }
    void harvest() { printf("northern veggie harvest\n"); }
};
class TropicalVeggie : public Veggie {
public:
    void grow() { printf("tropical veggie grow\n"); }
    void plant() { printf("tropical veggie plant\n"); }
    void harvest() { printf("tropical veggie harvest\n"); }
};

class Factory {
public:
    virtual Fruit* createFruit() = 0;
    virtual Veggie* createVeggie() = 0;
};
class NorthernFactory : public Factory{
public:
    Fruit* createFruit() {
        NorthernFruit* nf = new NorthernFruit();
        nf->plant();
        nf->grow();
        nf->harvest();
        return nf;
    }
    Veggie* createVeggie() {
        NorthernVeggie* nv = new NorthernVeggie();
        nv->plant();
        nv->grow();
        nv->harvest();
        return nv;
    }
};
class TropicalFactory : public Factory{
public:
    Fruit* createFruit() {
        TropicalFruit* nf = new TropicalFruit();
        nf->plant();
        nf->grow();
        nf->harvest();
        return nf;
    }
    Veggie* createVeggie() {
        TropicalVeggie* nv = new TropicalVeggie();
        nv->plant();
        nv->grow();
        nv->harvest();
        return nv;
    }
};

int main() {
    Factory* factory1 = new NorthernFactory();
    factory1->createFruit();
    printf("\n");
    factory1->createVeggie();
    printf("\n");

    Factory* factory2 = new TropicalFactory();
    factory2->createFruit();
    printf("\n");
    factory2->createVeggie();
    printf("\n");

	return 0;
}
