//2bit
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		int m = board.size(), n = m ? board[0].size() : 0;
		for(int r = 0; r < m; r += 1)
		{
			for(int c = 0; c < n; c += 1)
			{
				int count = 0;
				for(int i = max(0, r-1); i < min(m, r+2); i += 1)
				{
					for(int j = max(0, c-1); j < min(n, c+2); j += 1)
					{
						count += board[i][j] & 1;
					}
				}
				if(count == 3 || count - board[r][c] == 3)
					board[r][c] |= 2;
			}
		}


		for(int r = 0; r < m; r += 1)
		{
			for(int c = 0; c < n; c += 1)
			{
				board[r][c] >>= 1;
			}
		}
	}
};

//straight forward
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		if(board.empty()) return; 
		vector<vector<int>> next(board);
		int row = board.size(), col = board[0].size();
		for(int r = 0; r < row; r += 1)
		{
			for(int c = 0; c < col; c += 1)
			{
				int sum = 0;
				if(r > 0)
				{
					sum += board[r-1][c];
					if(c > 0) sum += board[r - 1][c - 1];
					if(c < col - 1) sum += board[r - 1][c + 1];
				}
				

				if(c > 0) sum += board[r][c - 1];
				if(c < col - 1) sum += board[r][c + 1];

				if(r < row - 1)
				{
					sum += board[r+1][c];
					if(c > 0) sum += board[r + 1][c - 1];
					if(c < col - 1) sum += board[r + 1][c + 1];
				}

				if(board[r][c] == 1)
				{
					if(sum < 2 || sum > 3) next[r][c] = 0;
					else next[r][c] = 1;
				}
				else
				{
					if(sum == 3) next[r][c] = 1;
					else next[r][c] = 0;
				}
			}
		}
		board = next;
    }
};
