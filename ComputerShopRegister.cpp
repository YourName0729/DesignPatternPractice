#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Part {
private:
	int basePrice;
	string id;
	
public:
	void setId(string id){ this->id = id; }
	string getId(){ return id; }
	void setPrice(int price){ this->basePrice = price; }
	int getPrice(){ return basePrice; }
};

class Motherboard : public Part{
private:
	int frequency;
	
public:
	void setFrequency(int frequency){ this->frequency = frequency; }
	int getFrequency(){ return frequency; }
};

class Memory : public Part{
private:
	int capacity;

public:
	void setCapacity(int capacity){ this->capacity = capacity; }
	int getCapacity(){ return capacity; }
};

class Transaction {
protected:
	static vector<Part> parts;
	static Transaction* addr;
	
public:
	Transaction() {
		parts.clear();
		addr = NULL;
	}
	static Transaction* getTrnsc() {
		if(addr == NULL)
			addr = new Transaction();
		return addr;
	}
	void addProduct(Part& part) {
		parts.push_back(part);
	}
	int totalPrice() {
		int sum = 0;
		for(unsigned int i = 0; i < parts.size(); i++) {
			sum += parts[i].getPrice();
		}
		return sum;
	}
	void content() {
		for(unsigned int i = 0; i < parts.size(); i++) {
			printf("%d ID : %s, price : %d\n", i + 1, 
				parts[i].getId().c_str(), 
				   parts[i].getPrice());
		}
	}
};

/*be careful of this!!!!
  static member veriable must initilize at it's .cpp or afer declare it*/
vector<Part> Transaction::parts;
Transaction* Transaction::addr;

int main() {
	Motherboard MB1;
	Memory MM1;
	Transaction* tran1 = Transaction::getTrnsc();
	Transaction* tran2 = Transaction::getTrnsc();
	
	MB1.setId("MB11");
	MB1.setFrequency(20);
	MB1.setPrice(500);
	
	MM1.setId("MM11");
	MM1.setCapacity(330);
	MM1.setPrice(510);
	
	tran1->addProduct(MB1);
	tran2->content();
	tran2->addProduct(MM1);
	tran1->content();
	printf("price : %d\n", tran1->totalPrice());
	printf("price : %d\n", tran2->totalPrice());
	
	return 0;
}
