class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSum = 0;
        int curSum = 0;
        for(int& num : nums)
        {
            curSum += num;
            minSum = min(minSum, curSum);
        }
        return 1 - minSum;
    }
};
