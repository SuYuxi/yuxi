class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char> opers;
		int i = 0, j = 0;
		while(j < input.size())
		{
			if(input[j] > '9' || input[j] < '0')
			{
				opers.emplace_back(input[j]);
				nums.emplace_back(stoi(input.substr(i, j - i)));
				i = j + 1;
			}
			j++;
		}
		nums.emplace_back(stoi(input.substr(i, j - i)));
		
		return divideAndConquer(nums, opers, 0, nums.size() - 1);
    }
private:
	vector<int> divideAndConquer(vector<int>& nums, vector<char>& opers, int start, int end) {
		vector<int> res;
		if(start == end) res.emplace_back(nums[start]);
		for(int i = start; i < end; i++)
		{
			vector<int> res1 = divideAndConquer(nums, opers, start, i);
			vector<int> res2 = divideAndConquer(nums, opers, i + 1, end);
			if(opers[i] == '+')
			{
				for(int& m : res1)
				{
					for(int& n : res2)
					{
						res.emplace_back(m + n);
					}
				}
			}
			else if(opers[i] == '-')
			{
				for(int& m : res1)
				{
					for(int& n : res2)
					{
						res.emplace_back(m - n);
					}
				}
			}
			else if(opers[i] == '*')
			{
				for(int& m : res1)
				{
					for(int& n : res2)
					{
						res.emplace_back(m * n);
					}
				}
			}
		}
		return res;
	}
};
