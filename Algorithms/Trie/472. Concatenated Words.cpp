//Trie
struct TrieNode {
	TrieNode* children[26];
	bool isWord = false;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;
		TrieNode* root = buildTrie(words);	
		for(string& word : words)
		{
			if(word.empty()) continue;
			if(verify(word, root, 0, 0)) res.emplace_back(word);
		}
		return res;
    }

private:
	TrieNode* buildTrie(vector<string>& words) {
		//build Trie
		TrieNode* root = new TrieNode();
		for(string& word : words)
		{
			if(word.empty()) continue;
			TrieNode* node = root;
			for(char& c : word)
			{
				if(!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
				node = node->children[c - 'a'];
			}
			node->isWord = true;
		}
		return root;
	}

	bool verify(string& word, TrieNode* root, int inx, int count) {
		TrieNode* node = root;
		int n = word.size();
		for(int i = inx; i < n; i++)
		{
			if(!node->children[word[i] - 'a']) return false;
			node = node->children[word[i] - 'a'];
			if(node->isWord)
			{
				if(i == n - 1) return count >= 1;
				if(verify(word, root, i + 1, count + 1)) return true;
			}
		}
		return false;
	}
};

//DFS + DP
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){ return a.size() < b.size(); });
		unordered_set<string> dict;
		vector<string> res;
		for(string& word : words)
		{
			if(verify(word, dict))
			{
				res.emplace_back(word);
			}
			dict.insert(word);
		}
		return res;
    }
	bool verify(string& word, unordered_set<string>& dict) {
		if(word.empty()) return false;
		int n = word.size();
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(dp[j] && dict.count(word.substr(j, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};
