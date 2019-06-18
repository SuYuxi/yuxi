struct TrieNode {
	unordered_map<char, TrieNode*> children;
	string word = "";
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		if(board.empty()) return {};
		m = board.size(), n = board[0].size();
		//build TrieTree
		TrieNode* root = new TrieNode();
		for(string& word : words)
		{
			TrieNode* node = root;
			for(char& c : word)
			{
				if(node->children[c] == nullptr) node->children[c] = new TrieNode();
				node = node->children[c];
			}
			node->word = word;
		}
		//backtracking
		vector<string> res;

		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				check(board, root, i, j, res);
			}
		}
		return res;
    }
private:
	int m, n;
	void check(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& res) {
		char c = board[i][j];
		if(node->children.count(c) == 0) return;
		node = node->children[c];
		if(!node->word.empty()) 
		{
			res.emplace_back(node->word);
			node->word = "";
		}
		board[i][j] = '$';
		if(i < m - 1) check(board, node, i + 1, j, res);
		if(i > 0)check(board, node, i - 1, j, res);
		if(j < n - 1)check(board, node, i, j + 1, res);
		if(j > 0)check(board, node, i, j - 1, res);
		board[i][j] = c;
	}
};

