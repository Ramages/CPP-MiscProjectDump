#include <iostream> //Printing
#include <random> //randomizing

int main()
{
	std::random_device rand_dev;
	std::mt19937 num_gen(rand_dev());
	std::uniform_int_distribution<> dist(1,900);

	num_gen.seed(0);
	dist.reset();

	while(true)
	{
		std::cout << "\n";

		for(int j = 0; j < dist(num_gen); j++)
		{
			std::cout << " ";
			if(dist(num_gen) % 32 == 4){std::cout << "*";}
		}

		//std::cout << "*";

		std::this_thread::sleep_for(std::chrono::milliseconds(80));
	}
}