class Solution {
public:
    bool isPerfectSquare(int num) {
		long lower = 1, upper = num;
		long mid, square;
		while(lower <= upper)
		{
			mid = lower + (upper - lower) / 2;
			square = pow(mid, 2);	
			if(square == num) return true;
			if(square < num)
			{
				lower = mid + 1;
			}
			else
			{
				upper = mid - 1;
			}
		}
		return false;
    }
};

#Newton Method
class Solution {
public:
    bool isPerfectSquare(int num) {
		long x = num;
		while(pow(x, 2) > num)
		{
			x = (x + num / x) >> 1;
		}
		return pow(x, 2) == num;
    }
};

