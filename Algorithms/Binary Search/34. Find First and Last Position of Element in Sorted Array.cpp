class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> range = {-1, -1};
		int left = binarySearch(nums, target, true);
		if(left == nums.size() || nums[left] != target) return range;
		range[0] = left;
		range[1] = binarySearch(nums, target, false) - 1;
		return range;
    }

	int binarySearch(vector<int>& nums, int target, bool searchLeft) {
		int left = 0, right = nums.size();
		while(left < right)
		{
			int mid = (left + right) / 2;
			if(nums[mid] > target || (nums[mid] == target && searchLeft))
			{
				right = mid;	
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
};
