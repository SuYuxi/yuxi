/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//DFS
/*
class Solution {
public:
    std::unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        if(visited.find(node) != visited.end()) {
            return visited[node];
        }
        visited[node] = new Node(node->val);
        for(Node* adj : node->neighbors) {
            visited[node]->neighbors.emplace_back(cloneGraph(adj));
        }
        return visited[node];
    }
}
*/

//BFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        std::unordered_map<Node*, Node*> visited;
        std::queue<Node*> q;
        q.emplace(node);
        visited[node] = new Node(node->val);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for(Node* adj : cur->neighbors) {
                if(visited.find(adj) == visited.end()) {
                    visited[adj] = new Node(adj->val);
                    q.emplace(adj);
                }
                visited[cur]->neighbors.emplace_back(visited[adj]);
            }
        }
        return visited[node];
    }
};
