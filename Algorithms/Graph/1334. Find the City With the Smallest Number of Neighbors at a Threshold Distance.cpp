class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> connections(n, vector<int>(n, distanceThreshold + 1));
        for(int i = 0; i < n; ++i)
        {
            connections[i][i] = 0;
        }
        for(vector<int>& edge : edges)
        {
            connections[edge[0]][edge[1]] = edge[2];
            connections[edge[1]][edge[0]] = edge[2];
        }
        for(int k = 0; k < n; ++k)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    connections[i][j] = min(connections[i][j], connections[i][k] + connections[k][j]);
                }
            }
        }
        int minCnt = INT_MAX;
        int res = -1;
        for(int i = 0; i < n; ++i)
        {
            int cnt = 0;
            for(int j = 0; j < n; ++j)
            {
                cnt += connections[i][j] <= distanceThreshold;
            }
            if(cnt <= minCnt)
            {
                res = i;
                minCnt = cnt;
            }
        }
        return res;
    }
};
