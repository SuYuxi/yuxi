class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = max(horizontalCuts[0], h - horizontalCuts.back());
        int maxW = max(verticalCuts[0], w - verticalCuts.back());
        for(int i = 1; i < horizontalCuts.size(); ++i)
        {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for(int i = 1; i < verticalCuts.size(); ++i)
        {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (long)maxW * maxH % 1000000007;
    }
};
