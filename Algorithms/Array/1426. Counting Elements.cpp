class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> dict;
        for(int& num : arr)
        {
            dict[num] += 1;
        }
        int cnt = 0;
        for(auto& p : dict)
        {
            if(dict.count(p.first + 1) != 0)
            {
                cnt += p.second;
            }
        }
        return cnt;
    }
};
