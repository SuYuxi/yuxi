class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int, int> count;
        int result = 0;
        for(int &i : nums) {
            counter[i] += 1;
        }
        
        for(auto &p : count)
        {
            result += p.second * (p.second - 1) / 2;
        }
        return result;
    }
};
