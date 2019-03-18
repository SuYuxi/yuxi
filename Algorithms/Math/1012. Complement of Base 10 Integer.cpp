class Solution {
public:
    int bitwiseComplement(int N) {
		int bound = 2;
		while(N > bound - 1)
		{
			bound *= 2;
		}
		return bound - 1 - N;
    }
};
