class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
		unordered_set<string> encodeSet;
		for(string& word : words)
		{
			string encode = "";
			for(char& c : word)
			{
				encode += table[c - 'a'];
			}
			encodeSet.insert(encode);
		}
		return encodeSet.size();
    }
};
