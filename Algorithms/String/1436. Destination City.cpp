class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> citys;
        for(vector<string>& path : paths)
        {
            citys[path[1]] |= false;
            citys[path[0]] |= true;
        }
        for(auto& city : citys)
        {
            if(!city.second) return city.first;
        }
        return "";
    }
};
