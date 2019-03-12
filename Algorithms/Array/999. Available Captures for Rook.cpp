class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
		if(board.empty()) return 0;
		for(int row = 0; row < board.size(); row += 1)
		{
			for(int col = 0; col < board[0].size(); col += 1)
			{
				if(board[row][col] == 'R')
				{
					int Rrow = row;
					int Rcol = col;
					int res = 0;

					for(int col = Rcol - 1; col >= 0; col -= 1)
					{
						if(board[Rrow][col] != '.')
						{
							if(board[Rrow][col] == 'p') res += 1;
							break;
						}
					}

					for(int col = Rcol + 1; col < board[0].size(); col += 1)
					{
						if(board[Rrow][col] != '.')
						{
							if(board[Rrow][col] == 'p') res += 1;
							break;
						}
					}

					for(int row = Rrow - 1; row >= 0; row -= 1)
					{
						if(board[row][Rcol] != '.')
						{
							if(board[row][Rcol] == 'p') res += 1;
							break;
						}
					}

					for(int row = Rrow + 1; row < board.size(); row += 1)
					{
						if(board[row][Rcol] != '.')
						{
							if(board[row][Rcol] == 'p') res += 1;
							break;
						}
					}
					return res;
				}
			}
		}
		return 0;
    }
};
