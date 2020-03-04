#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP
#include <iostream>

#undef new

class Vector
{
private:

	std::string *elements;
	unsigned long long size;
	unsigned long long num_of_elem;

public:

	Vector(); //Default constructor

	Vector(unsigned long long); //long long constructor

	~Vector(); //Destructor

	std::string& operator[] (const unsigned long long); //Subscript operator

	Vector(const Vector& other); //Copy constructor

	Vector& operator=(const Vector&); //Copy assignment

	void PushBack(const std::string& object); //Adds new element at end of array

	void Resize(unsigned long long size); //Makes the buffer size same as the desired size 

	void PopBack(); //Removes last(empty) element in array

	void ShrinkToFit();	//Makes the array the size of the ammount of elements in it 

	unsigned long long Size() const; //Returns the number of elements in the array

	unsigned long long Capacity() const; //Returns the size of the array
};

#endif