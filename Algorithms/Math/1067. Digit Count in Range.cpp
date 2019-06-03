class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return count(d, high) - count(d, low - 1);
    }

	int count(int digit, int n) {
		int cnt = 0;
		if(digit != 0)
		{
			for(int num = 1; num <= n; num *= 10)
			{
				int divisor = num * 10;
				cnt += (n / divisor) * num;
				cnt += min(max(n % divisor - digit * num + 1, 0), num);
			}
		}
		else
		{
			for(int num = 1; num <= n; num *= 10)
			{
				int divisor = num * 10;
				cnt += (n / divisor) * num;
				if(n / divisor > 0)
				{
					cnt -= num;
					cnt += min(n % divisor + 1, num);
				}
			}
		}
		return cnt;
	}
};
