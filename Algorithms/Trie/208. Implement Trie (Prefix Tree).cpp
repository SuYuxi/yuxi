struct TrieNode {
	bool isWord;
	vector<TrieNode*> next;
	TrieNode() : next(vector<TrieNode*>(26, nullptr)) , isWord(false) { }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		if(word.empty()) return;
		TrieNode* cur = root;
		for(int i = 0, inx = 0; i < word.size(); i += 1)
		{
			inx = word[i] - 'a';
			if(cur->next[inx] == nullptr)
			{
				cur->next[inx] = new TrieNode();
			}
			cur = cur->next[inx];	
		}
		cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		TrieNode* cur = root;
		for(char& c : word)
		{
			int inx = c - 'a';
			if(cur->next[inx] == nullptr) return false;
			cur = cur->next[inx];
		}
		return cur->isWord ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		TrieNode* cur = root;
		for(char& c : prefix)
		{
			int inx = c - 'a';
			if(cur->next[inx] == nullptr) return false;
			cur = cur->next[inx];
		}
		return true;
    }

private:
	TrieNode* root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
