class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if(board.empty()) return false;
		char c = word[0];
		m = board.size();
		n = board[0].size();
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(board[i][j] == c && check(board, word, 0, i, j)) return true;
			}
		}
		return false;
    }
private:
	int m, n;
	bool check(vector<vector<char>>& board, string& word, int inx, int r, int c) {
		if(word[inx] != board[r][c]) return false;	
		if(inx == word.size() - 1) return true;
		board[r][c] = '$';
		if(r < m - 1 && check(board, word, inx + 1, r + 1, c))
		{
			board[r][c] = word[inx];
			return true;
		}
		if(r > 0 && check(board, word, inx + 1, r - 1, c))
		{
			board[r][c] = word[inx];
			return true;
		}
		if(c < n - 1 && check(board, word, inx + 1, r, c + 1))
		{
			board[r][c] = word[inx];
			return true;
		}
		if(c > 0 && check(board, word, inx + 1, r, c - 1))
		{
			board[r][c] = word[inx];
			return true;
		}
		board[r][c] = word[inx];
		return false;
	}
};
