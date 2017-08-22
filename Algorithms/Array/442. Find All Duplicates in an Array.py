class Solution(object):
	def findDuplicates(self, nums):
		ans = []
		for v in nums:
			if(nums[abs(v)-1] > 0):
				nums[abs(v)-1] *= -1
			else:
				ans.append(abs(v))
		return ans

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;
		for(int& inx : nums) {
			if(nums[abs(inx)-1] > 0)
				nums[abs(inx)-1] *= -1;
			else
				ans.push_back(abs(inx));
		}
		return ans;
	}
};

var findDuplicates = function(nums) {
	var ans = [];
	for (var inx = 0;inx < nums.length; inx += 1) {
		if(nums[Math.abs(nums[inx])-1] > 0)
			nums[Math.abs(nums[inx])-1] *= -1;
		else
			ans.push(Math.abs(nums[inx]));
	}
	return ans;
};
