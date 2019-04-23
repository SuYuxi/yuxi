class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> cells(R * C, vector<int>(2));
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				cells[i * C + j] = {i, j};
			}
		}
		sort(cells.begin(), cells.end(), [r0, c0](const vector<int>& a, const vector<int>& b){ return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0); });

		return cells;
    }
};
