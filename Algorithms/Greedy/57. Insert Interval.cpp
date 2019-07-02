class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int inx = 0;
		int n = intervals.size();
        vector<vector<int>> res;
		//add all intervals starting before newInterval
		while(inx < n && intervals[inx][0] < newInterval[0])
		{
			res.emplace_back(intervals[inx]);	
			inx++;
		}
		//add newInterval
		if(res.empty() || res.back()[1] < newInterval[0])
		{
			res.emplace_back(newInterval);	
		}
		else
		{
			res.back()[1] = max(res.back()[1], newInterval[1]);
		}
		//add new intervals, merge with newInterval if needed
		while(inx < n)
		{
			if(res.back()[1] < intervals[inx][0])
			{
				res.emplace_back(intervals[inx]);	
			}
			else
			{
				res.back()[1] = max(res.back()[1], intervals[inx][1]);
			}
			inx++;
		}

        return res;
    }
};
