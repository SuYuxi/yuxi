class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int num = 0;
        for(int i = 0; i < startTime.size(); ++i)
        {
            if(startTime[i] <= queryTime && endTime[i] >= queryTime) num += 1;
        }
        return num;
    }
};
