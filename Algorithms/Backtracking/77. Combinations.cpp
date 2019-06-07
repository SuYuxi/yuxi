class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> nums;
		backtracking(1, n, k, nums, ans);
		return ans;
    }
	
private:
	void backtracking(int inx, int n, int k, vector<int>& nums, vector<vector<int>>& comb) {
		if(k == 0)
		{
			comb.emplace_back(nums);
			return;
		}
		for(int i = inx; i <= n - k + 1; i++)
		{
			nums.emplace_back(i);
			backtracking(i + 1, n, k - 1, nums, comb);
			nums.pop_back();
		}
	}
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		vector<int> nums;
		for(int i = 1; i <= k; i++)
		{
			nums.emplace_back(i);
		}
		nums.emplace_back(n + 1);
		int j = 0;
		while(j < k)
		{
			nums.pop_back();
			ans.emplace_back(nums);
			nums.emplace_back(n + 1);
			j = 0;
			while(j < k && nums[j] + 1 == nums[j + 1])
			{
				nums[j] = j + 1;
				j++;
			}
			nums[j]++;
		}
		return ans;
	}
};
