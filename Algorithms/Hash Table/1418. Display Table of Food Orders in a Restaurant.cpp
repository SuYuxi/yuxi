class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> menu;
        map<int, map<string, int>> tables;
        for(const vector<string>& order : orders)
        {
            menu.insert(order[2]);
            tables[stoi(order[1])][order[2]] += 1;
        }
        vector<vector<string>> ret;
        vector<string> header = {"Table"};
        for(const string& name : menu)
        {
            header.emplace_back(name);
        }
        ret.emplace_back(header);
        for(pair<const int, map<string, int>>& table : tables)
        {
            vector<string> row(menu.size() + 1, "0");
            row[0] = to_string(table.first);
            int i = 1;
            for(const string& name : menu)
            {
                if(table.second.count(name) != 0)
                {
                    row[i] = to_string(table.second[name]);
                }
                i += 1;
            }
            ret.emplace_back(row);
        }
        return ret;
    }
};
