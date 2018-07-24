#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Inventor {
private:
	int level;
public:
	Inventor(int l) : level(l){}
	int getLevel(){ return level; }
	virtual void update(string msg) = 0;
};
class FreeInventor : public Inventor {
public:
	FreeInventor() : Inventor(2){}
	void update(string msg) {
		printf("A Free User get message : %s\n", msg.c_str());
	}
};
class VIPInventor : public Inventor {
public:
	VIPInventor() : Inventor(5){}
	void update(string msg) {
		printf("A VIP User get message : %s\n", msg.c_str());
	}
};

class StockBroker {
private:
	vector<Inventor*> inventors;
public:
	void regist(Inventor* inventor) {
		inventors.push_back(inventor);
	}
	void remove(Inventor* inventor) {
		for(unsigned int i = 0; i < inventors.size(); i++) {
			if(inventors[i] == inventor)
				inventors.erase(inventors.begin() + i);
		}
	}
	void notify(string msg, int level) {
		for(unsigned int i = 0; i < inventors.size(); i++) {
			if(inventors[i]->getLevel() >= level)
				inventors[i]->update(msg);
		}
	}
};

int main() {
	FreeInventor me;
	VIPInventor professor;
	StockBroker school;

	school.regist(&me);
	school.notify("a new student", 0);

	school.regist(&professor);
	school.notify("a severe professor", 1);

	school.notify("there is a bad student", 5);

	school.remove(&me);
	school.notify("no bad student any more", 5);

	return 0;
}
