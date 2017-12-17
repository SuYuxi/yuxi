class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> res(rowIndex + 1);
		res[0] = 1;
		for(int row = 0;row <= rowIndex; ++row) {
			for(int col = row;col > 0; --col) {
				res[col] = res[col-1] + res[col];
			}
		}
		return res;
    }
};
