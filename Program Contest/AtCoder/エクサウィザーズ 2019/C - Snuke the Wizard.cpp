#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main()
{
	std::string input;

	std::getline(std::cin, input, ' ');
	int N = std::stoi(input);
	std::getline(std::cin, input);
	int Q = std::stoi(input);
	std::string squares;
	std::getline(std::cin, squares);
	std::vector<std::string> spells;

	while(std::getline(std::cin, input))
	{
		spells.emplace_back(input);
	}

	std::vector<int> golems(N, 1);
	int sum = N;
	std::unordered_map<char, vector<int>> mapper;
	for(int inx = 0; inx < N; inx += 1)
	{
		mapper[squares[inx]].emplace_back(inx);
	}

	for(std::string& input : spells)
	{
		vector<int> squares = mapper[input[0]];
		vector<int> preGolems(golems);
		for(int& inx : squares)
		{
			if(sum <= 0)
			{
				std::cout << std::to_string(sum) << std::endl;
				return 0;
			}
			if(input[2] == 'L')
			{
				if(inx > 0)
				{
					golems[inx - 1] += preGolems[inx];
				}
					golems[inx] -= preGolems[inx];
				if(inx == 0)
				{
					sum -= preGolems[inx];
				}
			}
			else
			{
				if(inx < N - 1)
				{
					golems[inx + 1] += preGolems[inx];
				}
					golems[inx] -= preGolems[inx];
				if(inx == N - 1)
				{
					sum -= preGolems[inx];
				}
			}
		}
	}

	std::cout << std::to_string(sum) << std::endl;

	return 0;
}

