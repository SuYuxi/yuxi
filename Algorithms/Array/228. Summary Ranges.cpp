class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {       
        vector<string> res;
        for(int i = 0; i < nums.size(); ++i) {
            int head = nums[i];
            while(i + 1 < nums.size() && nums[i] + 1== nums[i+1]) {
                ++i;
            }
            
            if(head == nums[i]) res.emplace_back(to_string(head));
            else res.emplace_back(to_string(head) + "->" + to_string(nums[i]));
        }
        return res;
    }
};
