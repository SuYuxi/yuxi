// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		int upper = n;
		int lower = 1;
		int mid, res;
		while(lower <= upper)
		{
			mid = lower + (upper - lower) / 2;
			res = guess(mid); 
			if(res == 0) return mid;
			if(res == -1)
			{
				upper = mid - 1;
			}
			else if(res == 1)
			{
				lower = mid + 1;
			}
		}
	return -1;
    }
};

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		int upper = n;
		int lower = 1;
		int mid1, mid2, res1, res2;
		while(lower <= upper)
		{
			mid1 = lower + (upper - lower) / 3;
			mid2 = upper - (upper - lower) / 3;
			res1 = guess(mid1); 
			res2 = guess(mid2); 
			if(res1 == 0) return mid1;
			if(res2 == 0) return mid2;
			if(res1 == -1)
			{
				upper = mid1 - 1;
			}
			else if(res2 == 1)
			{
				lower = mid2 + 1;
			}
			else
			{
				lower = mid1 + 1;
				upper = mid2 - 1;
			}
		}
	return -1;
    }
};

