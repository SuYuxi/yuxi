class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
		int left = 0, right = 0;
		int mid, days, cur;
		for(int& w : weights)
		{
			left = max(left,  w);
			right += w;
		}
		while(left < right)
		{
			mid = left + (right - left) / 2;
			cur = 0, days = 1;
			for(int& w : weights)
			{
				cur += w;
				if(cur > mid)
				{
					cur = w;
					days += 1;
				}
			}
			if(days > D)
			{
				left = mid + 1;
			}
			else
			{
				right = mid;
			}
		}
		return left;
	}
};
