//https://leetcode.com/problems/number-of-digit-one/solution/

class Solution {
public:
    int countDigitOne(int n) {
		return count(1, n);
    }
	
    long count(long digit, long n) {
		long cnt = 0;
		for(long num = 1; num <= n; num *= 10)
		{
			cnt += (n / (10 * num)) * num;
			cnt += min(max(n % (10 * num) - digit + 1, 0L), num);
			digit *= 10;
		}
		return cnt;
	}
};
