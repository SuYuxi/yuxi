class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int res = 1;
        double center[2][2];
        for(int i = 1; i < points.size(); ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                double l = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                if(l > 2 * r) continue;
                double half[2] = {0.5 * (points[i][0] + points[j][0]), 0.5 * (points[i][1] + points[j][1])};
                double d = sqrt(r*r - pow(points[i][0] - half[0], 2) - pow(points[i][1] - half[1], 2));
                center[0][0] = half[0] - (d * (points[i][1] - points[j][1]) / l);
                center[0][1] = half[1] + (d * (points[i][0] - points[j][0]) / l);
                center[1][0] = half[0] + (d * (points[i][1] - points[j][1]) / l);
                center[1][1] = half[1] - (d * (points[i][0] - points[j][0]) / l);
                
                int cur1 = 0, cur2 = 0;
                for(vector<int>& point : points)
                {
                    if(pow(point[0] - center[0][0], 2) + pow(point[1] - center[0][1], 2) <= pow(r, 2) + 0.00001) cur1 += 1;
                    if(pow(point[0] - center[1][0], 2) + pow(point[1] - center[1][1], 2) <= pow(r, 2) + 0.00001) cur2 += 1;
                }
                res = max(res, max(cur1, cur2));
            }
        }
        return res;
    }
};
