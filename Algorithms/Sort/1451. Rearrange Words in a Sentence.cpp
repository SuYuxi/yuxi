class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        map<int, string> dict;
        string cur;
        for(char& c : text)
        {
            if(c != ' ')
            {
                cur.push_back(c);
            }
            else
            {
                dict[cur.size()] += cur + " ";
                cur = "";
            }
        }
        if(!cur.empty()) dict[cur.size()] += cur + " ";
        string ans;
        for(pair<const int, string>& p : dict)
        {
            ans += p.second;
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};
