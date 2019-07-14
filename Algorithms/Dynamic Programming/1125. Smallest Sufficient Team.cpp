class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = people.size();
        int n = req_skills.size();
        map<int, vector<int>, greater<int>> dp; //<state, people_set> cannot replace it by unordered_map because insert new element(maybe due to vector container) will rehash the unordered_map and invalidate the iterator. (for(pair<const int, vector<int>>& state : dp))
        dp[0] = {};
        unordered_map<string, int> mapper;
        for(int i = 0; i < n; i++) mapper[req_skills[i]] = i;
        for(int inx = 0; inx < m; inx++)
        {
            int curSkillSet = 0;
            for(string& skill : people[inx])
            {
                curSkillSet |= 1 << mapper[skill];
            }
            for(pair<const int, vector<int>>& state : dp)
            {
                int comb = state.first | curSkillSet;
                if(comb == state.first) continue;
                if(dp.count(comb) == 0 || dp[comb].size() > state.second.size() + 1)
                {
                    dp[comb] = state.second;
                    dp[comb].emplace_back(inx);                    
                }
            }
        }
        return dp[(1 << n) - 1]; //return state with all one 111...111
    }
};
