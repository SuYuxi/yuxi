//Floyd–Warshall Algorithm
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> connections(n, vector<bool>(n, false));
        for(vector<int>& prerequisite : prerequisites)
        {
            connections[prerequisite[0]][prerequisite[1]] = true;
        }
        for(int k = 0; k < n; ++k)
        {
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(i == j) continue;
                    if(connections[i][k] && connections[k][j]) connections[i][j] = true;
                }
            }
        }
        vector<bool> ans;
        for(vector<int>& query : queries)
        {
            ans.emplace_back(connections[query[0]][query[1]]);
        }
        return ans;
    }
};
