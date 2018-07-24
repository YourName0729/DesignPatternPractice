#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Employee;
class IllgalEmployee;
class Manager;
class Developer;

class Employee {
private:
	string name;
	double salary;
public:
	Employee(){
		name = "";
		salary = 0;
	}
	Employee(string name, double salary) {
		setName(name);
		setSalary(salary);
	}
	void setName(string name) {
		this->name = name;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	string getName() {
		return name;
	}
	double getSalary() {
		return salary;
	}
	
	virtual void add(Employee& em) = 0;
	virtual void remove(Employee& em) = 0;
	virtual Employee& getchild(unsigned int i) = 0;
	virtual void myPrint() = 0;
	
	void print() {
		printf("%s\'s salary is %f\n", name.c_str(), salary);
		myPrint();
	};
	
	bool operator==(const Employee& em) const {
		return em.salary == salary && em.name == name;
	}
};

/*class IllegalEmployee : public Employee {
public:
	IllegalEmployee() {
		printf("there is an error call of Employee\n");
	}
	void myprint() {
		//printf("Do not have employee\n");
	}
	void add(Employee em) {
		//printf("Could not have employee\n");
	}
	Employee getchild(unsigned int i) {
		//printf("Could not have employee\n");
		//return IllegalEmployee();
	}
	void remove(Employee em) {
		//printf("Could not have employee\n");
	}
};*/

class Manager : public Employee {
private:
	vector<Employee*> employees;
public:
	Manager(string name, double salary) : Employee(name, salary){}
	void add(Employee &em){
		printf("add %s to %s\n", em.getName().c_str(), getName().c_str());
		employees.push_back(&em);
	}
	Employee& getchild(unsigned int i) {
		if(employees.size() <= i || i < 0) {
			printf("Illegal index\n");
			//return IllegalEmployee();
		}else		
			return *employees[i];
	}
	void myPrint() {
		//printf("go %s myprint\n", getName().c_str());
		for(unsigned int i = 0; i < employees.size(); i++) {
			employees[i]->print();
		}
	}
	void remove(Employee &em) {
		for(unsigned int i = 0; i < employees.size(); i++) {
			if(*employees[i] == em) {
				employees.erase(employees.begin() + i);
			}					
		}
		//if(!removed)
		//	printf("The Employee doesn\'t exist\n");		
	}
};

class Developer : public Employee {
public:
	Developer(string name, double salary) : Employee(name, salary){}
	void myPrint() {
		//printf("Do not have employee\n");
	}
	void add(Employee &em) {
		//printf("Could not have employee\n");
	}
	Employee& getchild(unsigned int i) {
		//printf("Could not have employee\n");
		//return IllegalEmployee();
	}
	void remove(Employee& em) {
		//printf("Could not have employee\n");
	}
};

int main() {
	Manager manager1("Tom",80000);
    Manager manager2("Mary",70000);
    Developer developer1("John",50000);
    Developer developer2("Kevin",40000);
    manager1.add(developer1);
    manager2.add(developer2);
    manager1.add(manager2);
    printf("\n");
    manager1.print();
    printf("\n");
    manager2.print();
    printf("\n");
    manager1.remove(developer1);
    manager1.print();
	return 0;
}
