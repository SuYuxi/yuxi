//https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
//Binary Search and Rabin-Karp(Rolling Hash)
class Solution {
public:
    string longestDupSubstring(string S) {
		int size = S.size();
		int low = 0, high = size; //length of duplicated substring
		int res = -1;
		while(low < high)
		{
			int mid = (low + 1 + high) / 2;
			int pos = search(S, mid);
			if(pos == -1)
			{
				high = mid - 1;
			}
			else
			{
				low = mid;
				res = pos;
			}
		}
		return res == -1 ? "" : S.substr(res, low);
    }

private:
	int search(string& S, int len) {
		if(len > S.size()) return -1;
		long MOD = 1e9 + 7;//prime
		int p = 113;//prime
		int pinv = pow(p, MOD - 2, MOD); //the mod inverse of p(MOD should be prime), by FERMAT's little therorem
		long hash = 0;
		long power = 1;
		for(int i = 0; i < len; i++)
		{
			hash = (hash + S[i] * power) % MOD;
			power = (power * p) % MOD;
		}
		unordered_map<long, int> seen;
		seen[hash] = 0;
		power = (power * pinv) % MOD;
		for(int i = len; i < S.size(); i++)
		{
			hash -= S[i - len];
			hash *= pinv;
			hash += S[i] * power;
			hash %= MOD;
			if(seen.count(hash) && S.substr(seen[hash], len) == S.substr(i - len + 1, len)) return i - len + 1;
			seen[hash] = i - len + 1;
		}
		return -1;
	}

	int pow(int x, int y, int m) {
		if(y == 0) return 1;
		long p = pow(x, y / 2, m);
		p = (p * p) % m;
		return (y % 2 == 0) ? p : (p * x) % m;
	}
};
