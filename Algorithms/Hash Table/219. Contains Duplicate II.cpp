class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		std::unordered_map<int, int> dict;
		for(int inx = 0; inx < nums.size(); inx++)
		{
			int num = nums[inx];
			if(dict.count(num) != 0 && dict[num] >= inx - k)
			{
				return true;
			}
			dict[num] = inx;
		}
		return false;
    }
};
