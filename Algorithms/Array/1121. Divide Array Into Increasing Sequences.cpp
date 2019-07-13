class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int maxCnt = 1;
        for(int i = 1, cnt = 1, pre = 0; i < nums.size(); i++)
        {
            if(nums[i] != pre)
            {
                pre = nums[i];
                cnt = 1;
            }
            else
            {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }
        }
        return K * maxCnt <= nums.size();
    }
};
