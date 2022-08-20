class Solution {
    public boolean isValidSudoku(char[][] board) {
        HashSet seen = new HashSet();
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    String code = "(" + board[i][j] + ")";
                    if(!seen.add(i + code) || !seen.add(code + j) || !seen.add(i/3 + code + j/3)) return false;
                }
            }
        }
        return true;
    }
}
