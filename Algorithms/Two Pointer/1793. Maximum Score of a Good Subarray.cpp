class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int size = nums.size();
        int inxL = k, inxR = k;
        int maxScore = nums[k];
        int mini = nums[k];
        
        while(inxL > 0 || inxR < size - 1) {
            if(inxL > 0 && inxR < size - 1) {
                if(nums[inxL - 1] > nums[inxR + 1]) --inxL;
                else ++inxR;
            }
            else if(inxL > 0) --inxL;
            else ++inxR;
            mini = min(mini, min(nums[inxL], nums[inxR]));
            maxScore = max(maxScore, mini * (inxR - inxL + 1));   
        }
        return maxScore;
    }
};
