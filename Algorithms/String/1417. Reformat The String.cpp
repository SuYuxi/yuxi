class Solution {
public:
    string reformat(string s) {
        string a, b;
        for(char& c : s)
        {
            if(isdigit(c))
            {
                a.push_back(c);
            }
            else
            {
                b.push_back(c);
            }
        }
        if(a.size() > b.size()) 
        {
            swap(a, b);
        }
        string ret;
        if(b.size() - a.size() > 1)
        {
            return ret;
        }    
        for(int i = 0; i < a.size(); ++i)
        {
            ret.push_back(b[i]);
            ret.push_back(a[i]);
        }
        if(b.size() > a.size())
        {
            ret.push_back(b.back());
        }
        return ret;
    }
};
