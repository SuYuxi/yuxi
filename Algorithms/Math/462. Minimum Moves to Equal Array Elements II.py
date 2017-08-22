class Solution(object):
	def minMoves2(self, nums):
		median = sorted(nums)[len(nums) >> 1]
		return sum(abs(median - i) for i in nums)

class Solution(object):
	def minMoves2(self, nums):
		nums.sort()
		return sum(nums[~i] - nums[i] for i in range(len(nums) // 2))

class Solution{
public:
	int minMoves2(vector<int>& nums) {
		int n = nums.size();
		auto it = nums.begin() + n/2;
		nth_element(nums.begin(), it, nums.end());
		int median = *it;
		int total = 0;
		for (auto &i : nums)
			total += abs(i - median);
		return total;
	}
};

