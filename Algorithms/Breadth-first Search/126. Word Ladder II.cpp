class Solution {
public:
	std::vector<std::vector<string>> result;
	std::map<string, bool> visited;
	std::map<string, std::vector<string>> neighbors;
	std::vector<string> path;

    vector<vector<string>> findLadders(string beginWord, string endWord, std::vector<string>& wordList) {
		std::unordered_set<string> wordSet(wordList.begin(), wordList.end());
		bool found = false;
		std::deque<string> queue;
		queue.emplace_back(beginWord);
		for(string &word : wordList)
		{
			visited[word] = false;
			neighbors[word] = std::vector<string>();
		}
		visited[beginWord] =true;

		while(!queue.empty())
		{
			if(found)
			{
				break;
			}

			for(string cur : queue)
			{
				wordSet.erase(cur);
			}

			int count = queue.size();
			for(int i = 0; i < count; i++)
			{
				string cur = queue.front();
				queue.pop_front();
				std::vector<string> nextNodes = findNextNodes(cur, wordSet);
				for(string node : nextNodes)
				{
					neighbors[cur].emplace_back(node);
					if(!visited[node])
					{
						visited[node] = true;
						if(node == endWord)
						{
							found = true;
						}
						else
						{
							queue.emplace_back(node);
						}
					}
				}
			}
		}

		findPath(beginWord, endWord, path);
		return result;
	}

	std::vector<string> findNextNodes(string word, std::unordered_set<string>& wordSet) {
		vector<string> nodes;
		for(int inx = 0; inx < word.size(); inx++)
		{
			string cur = word;
			for(char ch = 'a'; ch <= 'z'; ch++)
			{
				if(cur[inx] == ch)
				{
					continue;
				}
				cur[inx] = ch;
				if(wordSet.find(cur) != wordSet.end())
				{
					nodes.emplace_back(cur);
				}
			}
		}
		return nodes;
	}

	void findPath(string curWord, string endWord, std::vector<string> &path)
	{
		path.emplace_back(curWord);
		if(curWord == endWord)
		{
			result.emplace_back(path);
		}
		else
		{
			for(string nextNode : neighbors[curWord])
			{
				findPath(nextNode, endWord, path);
			}

		}
		path.pop_back();
	}
};

//two-end BFS
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		std::unordered_set<string> wordSet(wordList.begin(), wordList.end()); 
		std::unordered_set<string> frontWords, backWords;
		frontWords.insert(beginWord);
		if(wordSet.count(endWord)) backWords.insert(endWord);
		std::unordered_map<string, vector<string>> nextNodes;
		bool flip = false;
		std::vector<string> ladder;
		std::vector<vector<string>> ladders;
		ladder.emplace_back(beginWord);
		if(search(frontWords, backWords, wordSet, nextNodes, flip))
		{
			getLadders(beginWord, endWord, nextNodes, ladder, ladders);
		}

		return ladders;
    }

private:
	bool search(
	std::unordered_set<string> &frontWords,
	std::unordered_set<string> &backWords,
	std::unordered_set<string> &wordSet,
	std::unordered_map<string, vector<string>> &nextNodes,
	bool flip)
	{
		if(frontWords.empty()) return false;
		if(frontWords.size() > backWords.size()) return search(backWords, frontWords, wordSet, nextNodes, !flip);
		for(string word : frontWords) wordSet.erase(word);
		for(string word : backWords) wordSet.erase(word);

		bool done = false;
		std::unordered_set<string> nextLevel;
		for(string word : frontWords)
		{
			int length = word.size();
			for(int i = 0; i < length; i++)
			{
				string cur(word);
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					cur[i] = ch;
					if(cur == word) continue;
					if(backWords.count(cur))
					{
						done = true;
						flip ? nextNodes[cur].emplace_back(word) : nextNodes[word].emplace_back(cur);
					}
					else if(!done && wordSet.count(cur))
					{
						nextLevel.insert(cur);
						flip ? nextNodes[cur].emplace_back(word) : nextNodes[word].emplace_back(cur);
					}
				}
			}
		}
		return done || search(nextLevel, backWords, wordSet, nextNodes, flip);
	}

	void getLadders(
	string &beginWord,
	string &endWord,
	std::unordered_map<string, vector<string>> &nextNodes,
	std::vector<string> &ladder,
	std::vector<vector<string>> &ladders)
	{
		if(beginWord == endWord)
		{
			ladders.emplace_back(ladder);
		}
		else
		{
			for(string word : nextNodes[beginWord])
			{
				ladder.emplace_back(word);
				getLadders(word, endWord, nextNodes, ladder, ladders);
				ladder.pop_back();
			}
		}
	}

};
