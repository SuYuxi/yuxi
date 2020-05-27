class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(N + 1);
        visited = vector<int>(N + 1, -1);
        for(vector<int>& dislike : dislikes)
        {
            graph[dislike[0]].emplace_back(dislike[1]);
            graph[dislike[1]].emplace_back(dislike[0]);
        }
        for(int node = 1; node <= N; ++node)
        {
            if(visited[node] == -1 && !dfs(node, false)) return false;
        }
        return true;
    }
    bool dfs(int inx, int flag)
    {
        if(visited[inx] != -1) return visited[inx] == flag;
        visited[inx] = flag;
        for(int& node : graph[inx])
        {
            if(!dfs(node, !flag)) return false;
        }
        return true;
    }
private:
    vector<vector<int>> graph;
    vector<int> visited;
};
