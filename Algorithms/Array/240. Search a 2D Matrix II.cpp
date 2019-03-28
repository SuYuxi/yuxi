class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty() || matrix[0].empty()) return false;
		int rowLen = matrix.size(), colLen = matrix[0].size();
		for(int row = 0, col = colLen - 1, value = 0; row < rowLen && col >= 0;)
		{
			value = matrix[row][col];
			if(value == target) return true;
			if(value < target) row += 1;
			else col -= 1;
		}
		return false;
    }
};
