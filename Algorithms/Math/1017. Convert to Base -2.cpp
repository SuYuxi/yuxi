//https://www.geeksforgeeks.org/convert-number-negative-base-representation/
class Solution {
public:
    string baseNeg2(int N) {
		string res;
		int base = -2;
		while(N != 0)
		{
			int rem = N % base;
			N /= base;
			if(rem < 0)
			{
				N += 1; //equal N = (N + base) / base
				rem -= base;
			}
			res = to_string(rem) + res;
		}

        return res.empty() ? "0" : res;   
    }
};
