class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        std::map<int, std::vector<std::pair<int, int>>> graph;
        for(std::vector<int>& edge : times)
        {
            graph[edge[0]].emplace_back(std::make_pair(edge[1], edge[2]));
        }
        auto cmp = [](std::pair<int, int>& a, std::pair<int, int>& b) {return a.second > b.second;};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> heap(cmp);
        heap.emplace(make_pair(K, 0));
        std::map<int, int> dist;
        while(!heap.empty())
        {
            std::pair<int, int> node = heap.top();
            heap.pop();
            if(dist.find(node.first) != dist.end()) continue;
            dist[node.first] = node.second;
            for(std::pair<int, int>& edge : graph[node.first])
            {
                if(dist.find(edge.first) == dist.end())
                {
                    heap.emplace(std::make_pair(edge.first, edge.second + node.second));
                }
            }
        }
        if(dist.size() != N) return -1;
        int ans = 0;
        for(pair<int, int> d : dist)
        {
            ans = max(ans, d.second);
        }
        return ans;
    }
};