class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
		int maxScore = 0, cur = 0;
		for(int& a : A)
		{
			maxScore = max(maxScore, cur + a);
			cur = max(cur, a) - 1;
		}
		return maxScore;
    }
};
