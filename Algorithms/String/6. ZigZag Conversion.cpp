class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows <= 1) {
			return s;
		}
		string str[numRows];
		int step = 0, row = 0;
		for(int inx = 0; inx < s.size(); inx += 1) {
			str[row] += s[inx];
			if(row == 0) {
				step = 1;
			}
			else if(row == numRows-1) {
				step = -1;
			}
			row += step;
		}
		string result;
		for(auto i : str) {
			result += i;
		}
		return result;
    }
};
