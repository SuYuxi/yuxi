//Hierholzer's algorithm
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> flights;
        for(vector<string>& ticket : tickets)
        {
            flights[ticket[0]].emplace(ticket[1]);
        }
        vector<string> path;
        vector<string> stack = { "JFK" };
        while(!stack.empty())
        {
            while(!flights[stack.back()].empty())
            {
                string from = stack.back();
                stack.emplace_back(flights[from].top());
                flights[from].pop();
            }
            path.insert(path.begin(), stack.back());
            stack.pop_back();
        }
        return path;
    }   
};
