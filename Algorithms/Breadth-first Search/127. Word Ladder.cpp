class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
		if(wordSet.find(endWord) == wordSet.end()) return 0;
		if(beginWord == endWord) return 1;

		std::unordered_set<string> head = {beginWord};
		std::unordered_set<string> tail = {endWord};
		wordSet.erase(endWord);
		std::unordered_set<string> toVisit;
		int len = beginWord.length();
		int length = 1;
        
		while(!head.empty() && !tail.empty())
		{
			length++;
			if(head.size() > tail.size()) head.swap(tail);

			for(string word : head)
			{
				for(int inx = 0; inx < len; inx++)
				{
					string cur = word;
					for(char ch = 'a'; ch <= 'z'; ch++)
					{
						cur[inx] = ch;
						if(tail.find(cur) != tail.end())
						{
							return length;
						}
						if(wordSet.find(cur) != wordSet.end())
						{
							toVisit.insert(cur);
							wordSet.erase(cur);
						}
					}
				}
			}
			head.swap(toVisit);
			toVisit.clear();
		}
        return 0;
    }
};
