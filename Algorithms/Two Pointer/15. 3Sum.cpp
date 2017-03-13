class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		int l = nums.size();
		for(int left = 0; left < l-2; left += 1) {
			if(nums[left] + nums[left+1] + nums[left+2] > 0) break;
			if(nums[left] + nums[l-2] + nums[l-1] < 0)	continue;
			if(left > 0 and nums[left] == nums[left-1]) continue;
			int mid = left + 1, right = l-1;
			int ref;
			while(mid < right) {
				ref = nums[left] + nums[mid] + nums[right];
				if(ref < 0) mid += 1;
				else if(ref > 0) right -= 1;
				else {
					res.push_back({nums[left], nums[mid], nums[right]});
					while(mid < right and nums[mid] == nums[mid+1]) mid += 1;
					while(mid < right and nums[right] == nums[right-1]) right -= 1;
					mid += 1, right -= 1;
				}
			}
		}
		return res;
    }
};
