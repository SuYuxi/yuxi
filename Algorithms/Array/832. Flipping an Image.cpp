class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		if(A.empty()) return A;
		int colL = A[0].size();
		for(vector<int>& row : A)
		{
			for(int col = 0; col < (colL + 1) / 2; col += 1)
			{
				int temp = row[col] ^ 1;
                row[col] = row[colL - col - 1] ^ 1;
				row[colL - col - 1] = temp;
			}
		}
		return A; 
    }
};
