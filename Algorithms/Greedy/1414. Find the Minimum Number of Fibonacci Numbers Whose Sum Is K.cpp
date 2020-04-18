class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int pre = 1, cur = 1;
        while(cur < k)
        {
            swap(pre, cur);
            cur += pre;
        }
        int cnt = 0;
        while(k > 0)
        {
            if(cur <= k) 
            {
                k -= cur;
                cnt += 1;
            }
            swap(pre, cur);
            pre = pre - cur;
        }
        return cnt;
    }
};
