class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
		double ans = 0;
		for(int i = 2; i < points.size(); i++)
		{
			for(int j = 1; j < i; j++)
			{
				for(int k = 0; k < j; k++)
				{
					double area = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1]));
					ans = max(ans, area);
				}
			}
		}
		return ans;
    }
};
