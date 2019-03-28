//Straight forward
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		for(int i = 0; i < nums.size() - 1; i += 1)
		{
			if(nums[i] > nums[i + 1]) return i;
		}
		return nums.size() - 1;
    }
};

//Binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() -1;
		int mid;
		while(left < right)
		{
			mid = (left + right) / 2;
			if(nums[mid] > nums[mid + 1])
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
