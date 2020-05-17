class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> hash;
        int size = favoriteCompanies.size();
        for(int i = 0, inx = 0; i < size; ++i)
        {
            for(string& name : favoriteCompanies[i])
            {
                if(hash.count(name) == 0)
                {
                    hash[name] = inx;
                    inx += 1;
                }
            }
        }
        
        vector<bitset<50000>> bitVec;
        for(int i = 0, inx = 0; i < size; ++i)
        {
            bitset<50000> bit;
            for(string& name : favoriteCompanies[i])
            {
                bit[hash[name]] = 1;
            }
            bitVec.emplace_back(bit);
        }
        vector<int> ans;
        for(int i = 0; i < size; ++i)
        {
            bool isSub = true;
            for(int j = 0; j < size; ++j)
            {
                if(i != j && ((bitVec[i] & bitVec[j]) == bitVec[i]))
                {
                    isSub = false;
                    break;
                }
            }
            if(isSub) ans.emplace_back(i);
        }        
        return ans;
    }
};
