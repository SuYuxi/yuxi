//Math
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
		vector<int> digits;
		int bits = 0;
		int size = D.size(); 
		for(int i = N + 1; i > 0; i /= 10)
		{
			digits.emplace_back(i % 10);
			bits += 1;
		}
		reverse(digits.begin(), digits.end());

		unordered_set<int> set1;
		for(string& s : D)
		{
			set1.insert(stoi(s));
		}

		int count = 0;
		for(int bit = 1; bit < bits; bit += 1)
		{
			count += pow(size, bit);
		}

		for(int inx = 0; inx < bits; inx += 1)
		{
			for(int digit = 0; digit < digits[inx]; digit += 1)
			{
				if(set1.count(digit))
				{
					count += pow(size, bits - inx - 1);
				}
			}
			if(set1.count(digits[inx]) == 0)
			{
				return count;
			}
		}
		return count;
    }
};

//Dp Time Limit Exceeded
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
		vector<int> dp(N + 1, 0);
		for(string& s : D)
		{
			dp[stoi(s)] = 1;
		}

		int count = 0;
		for(int num = 1; num <= N; num += 1)
		{
			if(num < 10)
			{
				if(dp[num] == 1)
				{
					count += 1;
				}
			}
			else
			{
				int a = num / 10;
				int b = num % 10;
				if(dp[a] == 1 && dp[b] == 1)
				{
					count += 1;
					dp[num] = 1;
				}
			}
		}
		return count;
	}
};
