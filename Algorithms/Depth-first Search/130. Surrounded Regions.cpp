class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        row = board.size();
        col = board[0].size();
        for(int i = 0; i < row; ++i)
        {
            check(board, i, 0);
            if(col > 1) check(board, i, col-1);
        }
        for(int j = 0; j < col; ++j)
        {
            check(board, 0, j);
            if(row > 1) check(board, row - 1, j);
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
    
private:
    int row, col;
    void check(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] == 'O')
        {
            board[x][y] = 'T';
            if(x > 0) check(board, x - 1, y);
            if(y > 0) check(board, x, y - 1);
            if(x < row - 1) check(board, x + 1, y);
            if(y < col - 1) check(board, x, y + 1);
        }
    }
};
