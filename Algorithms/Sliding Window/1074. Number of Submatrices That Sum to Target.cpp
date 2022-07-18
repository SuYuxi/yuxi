class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return 0;
        int h = matrix.size(), w = matrix[0].size();
        int res = 0;
        for(int r1 = 0; r1 < h; ++r1) {
            vector<int> prefixSum(w, 0);
            for(int r2 = r1; r2 < h; ++r2) {
                unordered_map<int, int> cnt = {{0, 1}};
                int cur = 0;
                for(int c = 0; c < w; ++c) {
                    cur += matrix[r2][c];
                    prefixSum[c] += cur;
                    res += cnt[prefixSum[c] - target];
                    ++cnt[prefixSum[c]];
                }
            }
        }
        return res;
    }
};
