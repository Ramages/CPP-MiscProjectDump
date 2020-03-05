#include <iostream>

void displayMemVal(int nInt_1, int* intPoint_1, int& referenceInt_1, int nInt_2, int* intPoint_2, int& referenceInt_2)
{
	std::cout << std::endl;
	std::cout << "Content of Int 1:                 " << nInt_1 << std::endl;
	std::cout << "Memory pos of Int 1:              " << &nInt_1 << std::endl;
	std::cout << "Dereferenced(value of) Pointer 1: " << *intPoint_1 << std::endl;
	std::cout << "Memory pos of Pointer 1:          " << intPoint_1 << std::endl;
	std::cout << "Content of Reference 1:           " << referenceInt_1 << std::endl;
	std::cout << "Memory pos of Reference 1:        " << &referenceInt_1 << std::endl;
	std::cout << std::endl;
	std::cout << "Content of Int 2:                 " << nInt_2 << std::endl;
	std::cout << "Memory pos of Int 2:              " << &nInt_2 << std::endl;
	std::cout << "Dereferenced(value of) Pointer 2: " << *intPoint_2 << std::endl;
	std::cout << "Memory pos of Pointer 2:          " << intPoint_2 << std::endl;
	std::cout << "Content of Reference 2:           " << referenceInt_2 << std::endl;
	std::cout << "Memory pos of Reference 2:        " << &referenceInt_2 << std::endl;
	std::cout << std::endl;
}


class BaseClass {
public:
	void print() {
		std::cout << "BaseClass!" << std::endl;
	}
};

class SubClass1 : public BaseClass {
public:
	virtual void print() {
		std::cout << "SubClass1!" << std::endl;
	}
};


class SubClass2 : public SubClass1 {
public:
	void print() {
		std::cout << "SubClass2!" << std::endl;
	}
};


int main()
{
	//This is to demonstrate how pointers and references work with regards to value assignment and memory.
	int normalInt_1 = 1;
	int normalInt_2 = 2;

	std::cout << "Assign Pointers by pointing them to references of Int 1 and 2" << std::endl;
	int* intP_1 = &normalInt_1;
	int* intP_2 = &normalInt_2;
	std::cout << std::endl;

	std::cout << "Assign Reference 1 and 2 to the value of Pointer 1 and Int 2" << std::endl;
	int& refInt_1 = *intP_1;
	int& refInt_2 = normalInt_2;

	displayMemVal(normalInt_1, intP_1, refInt_1, normalInt_2, intP_2, refInt_2);

	std::cout << std::endl;
	std::cout << "Assigning dereferenced Pointer 1 to Int 2" << std::endl;
	std::cout << std::endl;

	*intP_1 = normalInt_2;
	std::cout << "Dereferenced(value of) Pointer 1 after assigned to Int 2: " << *intP_1 << std::endl;
	std::cout << "Content of Reference 1:           " << refInt_1 << std::endl;

	std::cout << "Changing Int 1" << std::endl;	
	normalInt_1 = 3;
	std::cout << std::endl;

	std::cout << "Redirect Pointer 1 to point at Reference 2" << std::endl;	
	intP_1 = &refInt_2;

	std::cout << "Change the content of Reference 2" << std::endl;	
	refInt_2 = 4;

	displayMemVal(normalInt_1, intP_1, refInt_1, normalInt_2, intP_2, refInt_2);

	//Will the print function call print in BaseClass or SubClass1 or 2?
	BaseClass bc;
	SubClass1 sc1;
	SubClass2 sc2;

	BaseClass *baseclass_ptr = &sc2;
	baseclass_ptr->print();

	//Sizes of all common data types in C++

	int x = 0;
	long int y = 0; 
	long long int w = 0; 
	short int z = 0;
	char c;
	std::string str = "";
	float f = 0.0;
	double d = 0.0;
	int* intP;
	std::string& strP = str;

	std::cout << "Size of int: " << sizeof(x) << std::endl;
	std::cout << "Size of long: " << sizeof(y) << std::endl;
	std::cout << "Size of long long: " << sizeof(w) << std::endl;
	std::cout << "Size of short: " << sizeof(z) << std::endl;
	std::cout << "Size of char: " << sizeof(c) << std::endl;
	std::cout << "Size of string: " << sizeof(str) << std::endl;
	std::cout << "Size of float: " << sizeof(f) << std::endl;
	std::cout << "Size of double: " << sizeof(d) << std::endl;
	std::cout << "Size of pointer: " << sizeof(intP) << std::endl;
	std::cout << "Size of ref: " << sizeof(strP) << std::endl;

	return 0;
}