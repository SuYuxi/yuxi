class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
		vector<int> s = {a, b, c};
		sort(s.begin(), s.end());
		if(s[2] - s[0] == 2) return {0, 0};
		return {s[1] - s[0] <= 2 || s[2] - s[1] <= 2 ? 1: 2, s[2] - s[0] - 2};
    }
};
