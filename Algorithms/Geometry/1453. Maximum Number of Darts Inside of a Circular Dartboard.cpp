class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        int res = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(dist(points[i], points[j]) > 2 * r) continue;
                vector<vector<double>> center = getCenter(points[i], points[j], r);
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
    double dist(vector<int>& pointA, vector<int>& pointB) {
        return sqrt(pow(pointA[0] - pointB[0], 2) + pow(pointA[1] - pointB[1], 2));
    }
    
    vector<vector<double>> getCenter(vector<int>& pointA, vector<int>& pointB, int r) {
        vector<vector<double>> center(2, vector<double>(2));
        vector<double> half = {0.5 * (pointA[0] + pointB[0]), 0.5 * (pointA[1] + pointB[1])};
        double d = sqrt(r*r - pow(pointA[0] - half[0], 2) - pow(pointA[1] - half[1], 2));
        double l = dist(pointA, pointB);
        center[0][0] = half[0] - (d * (pointA[1] - pointB[1]) / l);
        center[0][1] = half[1] + (d * (pointA[0] - pointB[0]) / l);
        center[1][0] = half[0] + (d * (pointA[1] - pointB[1]) / l);
        center[1][1] = half[1] - (d * (pointA[0] - pointB[0]) / l);
        return center;
    }
};
