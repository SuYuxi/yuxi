class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> numSet;
		for(int& num : nums) numSet.insert(num);
		int longestSeq = 0;
		for(int num : numSet)
		{
			if(numSet.count(num - 1) == 0)
			{
				int curNum = num;
				while(numSet.count(curNum + 1))
				{
					curNum++;
				}
				longestSeq = max(longestSeq, curNum - num + 1);	
			}
		}
		return longestSeq;
    }
};
