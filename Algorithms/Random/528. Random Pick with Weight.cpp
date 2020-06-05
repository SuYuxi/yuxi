class Solution {
public:
    Solution(vector<int>& w) {
        range = w;
        for(int i = 1; i < range.size(); ++i)
        {
            range[i] += range[i - 1];
        }
        bound = range.back();
    }
    
    int pickIndex() {
        return upper_bound(range.begin(), range.end(), rand() % bound) - range.begin();        
    }
    vector<int> range;
    int bound;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
