#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class LegacyModule {
public:
	virtual void click(){
		printf("org normal click\n");
	}
	virtual void dbClick(){
		printf("org double click\n");
	}
	virtual void rightClick(){
		printf("org right click\n");
	}
};
class NewRequest {
public:
	virtual void mouseClick() {
		printf("new normal click\n");
	}
	virtual void mouseDbClick(){
		printf("new double click\n");
	}
	virtual void mouseRightClick(){
		printf("new right click\n");
	}
};
class Adapter : public NewRequest{
private:
	LegacyModule LM;
public:
	Adapter(LegacyModule& lm) {
		LM = lm;
	}
	void mouseClick() {
		LM.click();
	}
	void mouseDbClick(){
		LM.dbClick();
	}
	void mouseRightClick(){
		LM.rightClick();
	}
};

void test(NewRequest& nr) {
	nr.mouseClick();
	nr.mouseDbClick();
	nr.mouseRightClick();
	printf("\n");
}

int main() {
	LegacyModule org;
	NewRequest now;
	Adapter adp(org);
	
	test(now);
	test(adp);
	return 0;
}
