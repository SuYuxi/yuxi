//Straight forward
class Solution {
public:
    int clumsy(int N) {
		const int mod = 4;
		int factorial = 0;
		int part = -1;
		for(int i = 0, num = N; i < N; i += 1, num -= 1)
		{
			switch(i % mod)
			{
				case 0:
					part *= -num;
					break;
				case 1:
					part *= num;
					break;
				case 2:
					factorial += part / num;
					part = 0;
					break;
				case 3:
					factorial += num;
					if(i != N - 1)
						part = 1;
					break;
			}
		}
		factorial += part;
		return factorial;
    }
};

//Math
//https://leetcode.com/problems/clumsy-factorial/discuss/252279/You-never-think-of-this-amazing-O(1)-solution
class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;
        if (N == 3) return 6;
        if (N == 4) return 7;
        if (N % 4 == 1) return N + 2;
        if (N % 4 == 2) return N + 2;
        if (N % 4 == 3) return N - 1;
        return N + 1;
    }
};

//Recursion
class Solution {
public:
    int clumsy(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		if(N == 2) return 2;
		if(N == 3) return 6;
		return N * (N - 1) / (N - 2) + helper(N - 3);
    }

private:
	int helper(int N) {
		if(N == 0) return 0;
		if(N == 1) return 1;
		if(N == 2) return 1;
		if(N == 3) return 1;
		return N - (N - 1) * (N - 2) / (N - 3) + helper(N - 4);
	}
};

