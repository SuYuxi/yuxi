class Solution {
public:
    int numDupDigitsAtMostN(int N) {
		int res = 0;
		int bits = 0;
		vector<int> digits;
		for(int i = N + 1; i > 0; i /= 10)
		{
			digits.emplace_back(i % 10); 
			bits += 1;
		}
		reverse(digits.begin(), digits.end());

		//9876
		//XXX
		//XX
		//X
		for(int bit = 1; bit < bits; bit += 1)
		{
			res += 9 * permutation(9, bit - 1);
		}

		//Count number with same prefix
		//9876
		//1XXX ~ 8XXX
		//90XX ~ 97XX
		//980X ~ 986X
		//9870 ~ 9876
		unordered_set<int> visited;
		for(int i = 0; i < bits; i += 1)
		{
			for(int j = i > 0 ? 0 : 1; j < digits[i]; j += 1)
			{
				if(visited.count(j) == 0)
				{
					res += permutation(9 - i, bits - i - 1);
				}
			}
			if(visited.count(digits[i])) break;
			visited.insert(digits[i]);
		}

		return N - res;
    }

private:
	int permutation(int m, int n) {
		return n == 0 ? 1 : permutation(m, n - 1) * (m - n + 1);
	}
};
