class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int Maximum = INT_MIN;
        for(int& candy : candies)
        {
            Maximum = max(candy, Maximum);
        }

        for(int& candy : candies)
        {
            ans.emplace_back(candy + extraCandies >= Maximum);
        }
        return ans;
    }
};
