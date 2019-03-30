#include <string>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	std::string input;
	std::vector<int> length;
	while(getline(std::cin, input, ' '))
	{
		length.emplace_back(std::stoi(input));
	}

	if(length.empty())
	{
		std::cout<< "No" << std::endl;
		return 0;
	}

	for(int& num : length)
	{
		if(num != length[0])
		{
			std::cout<< "No" << std::endl;
			return 0;
		}
	}
	std::cout<< "Yes" << std::endl;
	return 0;
}
