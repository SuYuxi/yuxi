class Solution {
public:
    int heightChecker(vector<int>& heights) {
		vector<int> news = heights;
		sort(news.begin(), news.end());
		int ans = 0;
		for(int i = 0; i < heights.size(); i++)
		{
			if(heights[i] != news[i]) ans++;
		}
		return ans;
    }
};
