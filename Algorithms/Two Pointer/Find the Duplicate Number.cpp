class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0, hare = 0;
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }
        while(tortoise != hare);
        
        hare = 0;
        while(tortoise != hare)
        {
            hare = nums[hare];
            tortoise = nums[tortoise];
        }

        return hare;
    }
};
