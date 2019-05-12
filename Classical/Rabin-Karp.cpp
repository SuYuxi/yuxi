//Rabin-Karp (Rolling Hash)
//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
//https://leetcode.com/problems/repeated-string-match/solution/
#include<string>

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
		int q = (B.size() - 1) / A.size() + 1;
		int MOD = 1e9 + 7; //prime
		int p = 113; //prime
		int pinv = pow(p, MOD - 2, MOD); //the mod inverse of p(MOD should be prime), by FERMAT's little therorem
		long aHash = 0, bHash = 0;
		long power = 1;
		for(int i = 0; i < B.size(); i++)
		{
			bHash += B[i] * power;
			bHash %= MOD;
			power = (power * p) % MOD;
		}
		power = 1;
		for(int i = 0; i < B.size(); i++)
		{
			aHash += A[i % A.size()] * power;
			aHash %= MOD;
			power = (power * p) % MOD;
		}

		if(aHash == bHash && check(0, A, B)) return q;
		power = (power * pinv) % MOD;

		for(int i = B.size(); i < (q + 1) * A.size(); i++)
		{
			aHash -= A[(i - B.size()) % A.size()];
			aHash *= pinv;
			aHash += power * A[i % A.size()];
			aHash %= MOD;
			if(aHash == bHash && check(i - B.size() + 1, A, B))
			{
				return i < q * A.size() ? q : q + 1;
			}
		}
		return -1;
    }

	bool check(int inx, string A, string B) {
		int sizeA = A.size(), sizeB = B.size();
		for(int i = 0; i < sizeB; i++)
		{
			if(A[(inx + i) % sizeA] != B[i]) return false;
		}
		return true;
	}

	int pow(int x, int y, int m) 
	{ 
		if (y == 0) return 1; 
		long p = pow(x, y / 2, m) % m; 
		p = (p * p) % m; 
	  
		return (y % 2 == 0)? p : (x * p) % m; 
	} 
};
