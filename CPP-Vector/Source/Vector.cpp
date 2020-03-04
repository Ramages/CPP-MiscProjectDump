#include "Vector.hpp"
#include <iostream>

#undef new

//Default constructor
Vector::Vector()
{
	elements = nullptr;
	size = 0;
	num_of_elem = 0;
}

//long long constructor
Vector::Vector(unsigned long long sz)
{
	elements = new std::string[sz];
	size = sz;
	num_of_elem = 0;
}

//Copy constructor
Vector::Vector(const Vector& other): size(other.size), num_of_elem(other.num_of_elem)
{
	elements = new std::string[size];

	for(unsigned long long i = 0; i < other.num_of_elem; i++)
	{
		elements[i] = other.elements[i];
	}
}

//Copy assignment operator
Vector& Vector::operator=(const Vector& other)
{
	if(this != &other)
	{
		std::string* temp = new std::string[other.size];

		for(unsigned long long i = 0; i < other.num_of_elem; i++)
		{
			temp[i] = other.elements[i];
		}
		delete[] elements;
		this->elements = temp;
		this->num_of_elem = other.num_of_elem;
		this->size = other.size;
	}
	return *this;
}

//Subscript Operator
std::string& Vector::operator[](const unsigned long long INDEX)
{
	if(INDEX >= Size())
	{
		throw std::out_of_range{"Vector::operator[]"};
	}
	return elements[INDEX];
}

//Adds new element at end of array
void Vector::PushBack(const std::string& object)
{
	if(size < num_of_elem + 1)
	{
		std::string* temp = new std::string[size + 10];
		for(unsigned long long i = 0; i < size; i++)
		{
			temp[i] = elements[i];
		}
		temp[size] = object;
		delete[] elements;
		elements = temp;
		size += 10;
		num_of_elem += 1;
	}
	else
	{
		size = size;
		elements[num_of_elem] = object;
		num_of_elem += 1;
	}
}

//Resize the vector to desired size
void Vector::Resize(unsigned long long sz)
{
	std::string* temp = new std::string[sz];

	if(sz <= num_of_elem)
	{
		for(unsigned long long i = 0; i < sz; i++)
		{
			temp[i] = elements[i];
		}
		this->num_of_elem = sz;
	}
	else
	{
		for(unsigned long long i = 0; i < num_of_elem; i++)
		{
			temp[i] = elements[i];
		}
		this->num_of_elem = num_of_elem;
	}
	delete[] elements;
	this->elements = temp;
	this->size = sz;
}

//Shrinks the vector to the ammount of elements in it
void Vector::ShrinkToFit()
{
	Resize(num_of_elem);
}

//Removes last element in array
void Vector::PopBack()
{
	//Adds all elements except the last element into the current vector
	for(unsigned long long i = 0; i < num_of_elem - 1; i++)
	{
		this->elements[i] = elements[i];
	}
	this->num_of_elem = num_of_elem - 1;
}

//Returns the number of elements in the array
unsigned long long Vector::Size() const
{
	return num_of_elem;
}

//Returns the size of the array
unsigned long long Vector::Capacity() const
{
	return size;
}

//Destructor
Vector::~Vector()
{
	delete[] elements;
	size = 0;
	num_of_elem = 0;
}