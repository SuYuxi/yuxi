class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> dict(26);
        for(char& c : chars)
        {
            dict[c - 'a']++;
        }
        int ans = 0;
        for(string& word : words)
        {
            vector<int> count(dict);
            bool match = true;
            for(char& c : word)
            {
                if(--count[c - 'a'] < 0)
                {
                    match = false;
					break;
                }
            }
            if(match) ans += word.size();
        }
        return ans;
    }
};
