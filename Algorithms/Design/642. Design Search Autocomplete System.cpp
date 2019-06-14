//Trie and PriorityQueue
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
		root = new TrieNode();
		prefix = "";
		for(int i = 0; i < sentences.size(); i++)
		{
			add(sentences[i], times[i]);
		}
    }
    
	void add(string sentence, int time = 1) {
		TrieNode* node = root;
		for(char& c : sentence)
		{
			if(node->children.count(c) == 0)
			{
				node->children[c] = new TrieNode();
			}
			node = node->children[c];
			node->counts[sentence] += time;
		}
	}

    vector<string> input(char c) {
		vector<string> hotSentences;
		if(c == '#')
		{
			add(prefix, 1);
			prefix = "";
			return {};
		}
		else
		{
			prefix.push_back(c);
			TrieNode* node = root;
			for(char t : prefix)
			{
				if(node->children.count(t) == 0)
				{
					return {};
				}
				node = node->children[t];
				
			}
			auto cmp = [](pair<string, int>& p1, pair<string, int>& p2) {return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);};
			priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> sentencesQueue(cmp);
			for(pair<const string, int>& p: node->counts)
			{
				sentencesQueue.emplace(p);
			}
			for(int i = 0; i < 3 && !sentencesQueue.empty(); i++)
			{
				hotSentences.emplace_back(sentencesQueue.top().first);
				sentencesQueue.pop();
			}
		}
		return hotSentences;
    }


private:
	struct TrieNode {
		TrieNode() {
		}

		unordered_map<char, TrieNode*> children;
		unordered_map<string, int> counts; 
	};
	
	TrieNode* root;
	string prefix;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

