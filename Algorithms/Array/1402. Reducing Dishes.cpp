class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), less<int>());
        int total = 0;
        int res = 0;
        int size = satisfaction.size();
        for(int inx = size - 1; inx >= 0 && (total + satisfaction[inx] > 0); --inx) {
            total += satisfaction[inx];
            res += total;
        }
        return res;
    }
};
