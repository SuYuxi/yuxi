class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int lenRow = grid.size();
		if(lenRow == 0) return 0;
		int lenCol = grid[0].size();
		int rowMax[lenRow] = {}; //{} init is important!
		int colMax[lenCol] = {};
		int height = 0;
		for(int inxR = 0; inxR < lenRow; inxR += 1)
		{
			for(int inxC = 0; inxC < lenCol; inxC += 1)
			{
				rowMax[inxR] = max(rowMax[inxR], grid[inxR][inxC]);
				colMax[inxC] = max(colMax[inxC], grid[inxR][inxC]);
			}
		}

		for(int inxR = 0; inxR < lenRow; inxR += 1)
		{
			for(int inxC = 0; inxC < lenCol; inxC += 1)
			{
				height += min(rowMax[inxR], colMax[inxC]) - grid[inxR][inxC];
			}
		}
		return height;
    }
};
