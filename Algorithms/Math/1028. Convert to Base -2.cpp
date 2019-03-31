class Solution {
public:
    string baseNeg2(int N) {
		string res;
		int base = -2;
		int remainder;
		while(N != 0)
		{
			if(N % base < 0)
			{
				res.push_back('0' + N % base - base);
				N = (N / base) + 1;
			}
			else
			{
				res.push_back('0' + N % base);
				N = N / base;
			}
		}
		reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;   
    }
};
