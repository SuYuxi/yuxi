class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int maxP = nums[0];
		for(int i = 1, imax = nums[0], imin = nums[0]; i < nums.size(); i++)
		{
			if(nums[i] < 0)
				swap(imax, imin);
			imax = max(nums[i], imax * nums[i]); 
			imin = min(nums[i], imin * nums[i]); 
			maxP = max(maxP, imax);
		}
		return maxP;
    }
};
