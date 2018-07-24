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

class ErrorPart : public Part {	
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
private:
	vector<Part> parts;
	
public:
	void addProduct(Part& part) {
		parts.push_back(part);
	}
	Part findProduct(string id) {
		for(unsigned int i = 0; i < parts.size(); i++) {
			if(id == parts[i].getId()) {
				return parts[i];
			}
		}
		printf("%s is not found\n", id.c_str());
		return ErrorPart();
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
		printf("\n");
	}
};

int main() {
	Motherboard MB1;
	Memory MM1;
	Transaction tran;
	
	MB1.setId("MB1ID");
	MB1.setFrequency(20);
	MB1.setPrice(500);
	
	MM1.setId("MM1ID");
	MM1.setCapacity(330);
	MM1.setPrice(510);
	
	tran.addProduct(MB1);
	tran.content();
	printf("price : %d\n\n", tran.totalPrice());
	tran.addProduct(MM1);
	tran.content();
	Part found = tran.findProduct("MM1ID");
	tran.findProduct("404");
	printf("price : %d\n\n", tran.totalPrice());
	
	return 0;
}
