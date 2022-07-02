class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int units = 0;
        std::sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });
        for(int inx = 0; truckSize > 0 && inx < boxTypes.size(); ++inx) {
            vector<int> box = boxTypes[inx];
            int num = min(truckSize, box[0]);
            truckSize -= num;
            units += num * box[1];
        }
        return units;
    }
};
