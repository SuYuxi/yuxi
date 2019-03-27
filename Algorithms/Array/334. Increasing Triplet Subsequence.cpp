class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		int least = INT_MAX, second = INT_MAX;
		for(int& num : nums)
		{
			if(num <= least)
			{
				least = num;
			}
			else if(num <= second)
			{
				second = num;
			}
			else return true;
			
		}
		return false;
    }
};
