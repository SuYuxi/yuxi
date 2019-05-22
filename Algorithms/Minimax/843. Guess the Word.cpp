/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
//minimax
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
		for(int i = 0, m = 0; i < 10 && m < 6; i++)
		{
			int minZero = INT_MAX;
			string minStr;
			for(string& word1 : wordlist)
			{
				int num = 0;
				for(string& word2 : wordlist)
				{
					if(match(word1, word2) == 0) num++;
				}
				if(num < minZero)
				{
					minZero = num;
					minStr = word1;
				}
			}
			m = master.guess(minStr);
			vector<string> wordList2;
			for(string& str : wordlist)
			{
				if(match(minStr, str) == m) wordList2.emplace_back(str);
			}
			wordlist = wordList2;
		}
    }
private:
	int match(string& a, string& b) {
		int m = 0;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == b[i]) m++;
		}
		return m;
	}
};

//random guess
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
		for(int i = 0, m = 0; i < 10 && m < 6; i++)
		{
			string s = wordlist[rand() % wordlist.size()];
			m = master.guess(s);
			vector<string> wordList2;
			for(string& str : wordlist)
			{
				if(match(s, str) == m) wordList2.emplace_back(str);
			}
			wordlist = wordList2;
		}
    }
private:
	int match(string& a, string &b) {
		int m = 0;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == b[i]) m++;
		}
		return m;
	}
};
