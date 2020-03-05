#include <iostream>

unsigned int F(unsigned int n)
{
	if(n > 1)
	{
		return ((F(n - 1) + F(n - 2)));
	}
	else
	{
		return n;
	}
}

int main()
{
	unsigned int userNum;

	std::cout << "Enter your Fibonacci number: ";
	std::cin >> userNum;

	std::cout << "Number " << userNum << " of the Fibonacci sequence is: " << F(userNum) << std::endl;
}