//math
class Solution {
public:
    int rotatedDigits(int N) {
		unordered_set<int> set1 = {0, 1, 8};
		unordered_set<int> set2 = {0, 1, 8, 2, 5, 6, 9};
		int bits = 0;
		vector<int> digits;
		for(int i = N + 1; i > 0; i /= 10)
		{
			digits.emplace_back(i % 10);
			bits += 1;
		}
		reverse(digits.begin(), digits.end());

		int count = 0;
		bool flag = false;
		for(int bit = 0; bit < bits; bit += 1)
		{
			for(int digit = 0; digit < digits[bit]; digit += 1)
			{
				if(set2.count(digit) != 0)
				{
					count += pow(7, bits - bit - 1);
				}
				if(!flag && set1.count(digit) != 0)
				{
					count -= pow(3, bits - bit - 1);
				}
			}
			if(set2.count(digits[bit]) == 0)
			{
				return count;
			}
			else if(set1.count(digits[bit]) == 0)
			{
				flag = true;
			}
		}
		return count;
	}
};

//dp
class Solution {
public:
    int rotatedDigits(int N) {
		vector<int> dp(N + 1, 0);
		int count = 0;
		for(int i = 0; i < N + 1; i += 1)
		{
			if(i < 10)
			{
				if(i == 0 || i == 1 || i == 8) dp[i] = 1;
				else if(i == 2 || i == 5 || i == 6 || i == 9)
				{
					dp[i] = 2;
					count += 1;
				}
			}
			else
			{
				int a = dp[i / 10], b = dp[i % 10];
				if(a == 1 && b == 1) dp[i] = 1;
				else if(a >= 1 && b >= 1)
				{
					dp[i] = 2;
					count += 1;
				}
			}
		}
		return count;
    }
};

//straight forward
class Solution {
public:
    int rotatedDigits(int N) {
		int count = 0;
		for(int i = 1; i <= N; i += 1)
		{
			if(isValid(i)) count += 1;
		}
		return count;
	}

private:
	bool isValid(int num)
	{
		bool valid = false;
		int bit;
		while(num > 0)
		{
			bit = num % 10;
			num /= 10;
			switch(bit)
			{
				case 2: 
					valid = true;
					break;
				case 5:
					valid = true;
					break;
				case 6: 
					valid = true;
					break;
				case 9:
					valid = true;
					break;
				case 3:
					return false;
				case 4:
					return false;
				case 7:
					return false;
			}
			
		}
		return valid;
	}
};

