class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		int pos = -1;
		for(int inx = 0; inx < nums.size() - 1.; inx += 1)
		{
			if(nums[inx] > nums[inx + 1])
			{
				if(pos != -1) return false;
				pos = inx;
			}
		}

		if(pos == -1) return true;
		if(pos == 0 || pos == nums.size() - 2) return true;
		if(nums[pos-1] <= nums[pos+1] || nums[pos] <= nums[pos+2]) return true;
		return false;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
		bool changed = false;
		for(int inx = 0; inx < nums.size() - 1.; inx += 1)
		{
			if(nums[inx] > nums[inx + 1])
			{
				if(changed) return false;
				changed = true;
				if(inx == 0 || inx == nums.size() - 2)
					continue;
				if(nums[inx-1] <= nums[inx+1])
					continue;
				if(nums[inx] <= nums[inx + 2])
					continue;
				return false;
			}
		}
		return true;
	}
};
