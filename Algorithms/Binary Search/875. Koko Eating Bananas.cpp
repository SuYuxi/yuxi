class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
		int lo = 1, hi = pow(10, 9);
		int hours;
		while(lo < hi)
		{
			hours = 0;
			int mid = lo + (hi - lo) / 2;
			for(int& pile : piles)
			{
				hours += ((pile - 1) / mid) + 1; //ceil(float(pile) / mid)
			}
			if(hours > H)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		return lo;
    }
};

//straight forward
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        double sum = 0;
        for (int p : piles) {
            sum += p;
        }
        
        int k = ceil(sum / h);
        
        while (k > 1 && time_sum(piles, k) <= h)  k-= 1;
        while (time_sum(piles, k) > h) k += 1;
        
        return k;
    }

private:
    int time_sum(const vector<int>& piles, int k) {
        int sum = 0;
        for (int p : piles) {
            sum += ((p - 1) / k) + 1;
        }
        return sum;
    }
};
