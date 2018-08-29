class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		if(nums.size() < k || k == 0) return {};
		std::deque<int> d;
		vector<int> res;
		for(int inx = 0; inx < nums.size(); inx++)
		{
			int num = nums[inx];
			while(!d.empty() && nums[d.back()] <= num)
			{
				d.pop_back();
			}
			if(!d.empty() && d.front() == inx - k)
			{
				d.pop_front();
			}
			d.emplace_back(inx);
			if(inx >= k - 1)
			{
				res.emplace_back(nums[d.front()]);
			}
		}
		return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		if(nums.size() < k || k == 0) return {};
		int length = nums.size();
		vector<int> maxLeft(length, 0);
		vector<int> maxRight(length, 0);
		maxLeft[0] = nums[0];
		maxRight[length - 1] = nums[length - 1];
		for(int inx = 1; inx < length; inx++)
		{
			maxLeft[inx] = (inx % k == 0) ? nums[inx] : max(maxLeft[inx - 1], nums[inx]);
			int j = length - inx - 1;
			maxRight[j] = ((j + 1) % k == 0) ? nums[j] : max(maxRight[j + 1], nums[j]);
		}
		vector<int> res(length - k + 1, 0);
		for(int inx = 0; inx <= nums.size() - k; inx++)
		{
			res[inx] = max(maxRight[inx] , maxLeft[inx + k - 1]);
		}
		return res;
    }
};
