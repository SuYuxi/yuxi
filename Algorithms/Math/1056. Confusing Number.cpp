class Solution {
public:
    bool confusingNumber(int N) {
		if(N == 0) return false;
		unordered_set<int> invalid = {2, 3, 4, 5, 7};
		int num = N;
		int newNum = 0;
		bool ans = false;
		while(num > 0)
		{
			int digit = num % 10;
			if(invalid.count(digit) != 0) return false;
			newNum *= 10;
			if(digit == 6) newNum += 9;
			else if(digit == 9) newNum += 6;
			else newNum += digit;
			num /= 10;
		}
		return N != newNum;
    }
};
