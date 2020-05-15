//https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int curMax = 0, curMin = 0;
        int Sum = 0;
        for(int& num : A)
        {
            curMax = max(curMax + num, num);
            curMin = min(curMin + num, num);
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
            Sum += num;
        }
        return maxSum < 0 ? maxSum : max(maxSum, Sum - minSum);
    }
};
