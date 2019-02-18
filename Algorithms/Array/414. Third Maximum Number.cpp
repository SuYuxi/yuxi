class Solution {
public:
    int thirdMax(vector<int>& nums) {
		long max1 = std::numeric_limits<long>::min();
		long max2 = std::numeric_limits<long>::min();
		long max3 = std::numeric_limits<long>::min();
		for(int &num : nums)
		{
			if(num == max1 || num == max2 || num == max3) continue;
			if(num > max1)
			{
				max3 = max2;
				max2 = max1;
				max1 = num;
			}
			else if(num > max2)
			{
				max3 = max2;
				max2 = num;
			}
			else if(num > max3)
			{
				max3 = num;
			}
		}
		return max3 == std::numeric_limits<long>::min() ? max1 : max3;
    }
};
