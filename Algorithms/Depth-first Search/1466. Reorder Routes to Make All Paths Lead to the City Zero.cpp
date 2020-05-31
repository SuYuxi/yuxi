class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(vector<int>& connection : connections)
        {
            graph[connection[0]].emplace_back(connection[1]);
            graph[connection[1]].emplace_back(-connection[0]);
        }
        vector<bool> visited(n, false);
        return dfs(graph, visited, 0);
    }
    
private:
    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int inx) {
        int reorder = 0;
        visited[inx] = true;
        for(int& next : graph[inx])
        {
            if(!visited[abs(next)])
            {
                reorder += dfs(graph, visited, abs(next)) + (next > 0);
            }
        }
        return reorder;
    }
};
