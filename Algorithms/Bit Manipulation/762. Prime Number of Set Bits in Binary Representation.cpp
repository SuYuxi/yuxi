class Solution {
public:
    int countPrimeSetBits(int L, int R) {
		unordered_set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
		int cnt = 0;
		for(int num = L; num <= R; num += 1)
		{
			int bits = 0;
			for(int n = num; n != 0; n >>= 1)
			{
				bits += n & 1;
			}
			cnt += s.count(bits);
		}
		return cnt;
    }
};
