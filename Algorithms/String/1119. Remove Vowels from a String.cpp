class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        string res;
        for(char& c : S)
        {
            if(vowels.count(c) == 0) res.push_back(c);
        }
        return res;
    }
};
