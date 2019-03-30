#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	std::string input;
	std::getline(std::cin, input);
	int N = std::stoi(input);
	std::string hats;
	std::getline(std::cin, hats);

	int red = 0, blue = 0;
	for(char& hat : hats)
	{
		switch(hat)
		{
			case 'R':
				red += 1;
				break;
			case 'B':
				blue += 1;
				break;
		}
	}

	if(red > blue)
	{
		std::cout<< "Yes" << std::endl;
	}
	else
	{
		std::cout<< "No" << std::endl;
	}
	return 0;
}
