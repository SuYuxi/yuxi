class Solution {
public:
    int longestWPI(vector<int>& hours) {
		unordered_map<int, int> pos;
		int res = 0, cnt = 0;
		for(int i = 0; i < hours.size(); i++)
		{
			cnt += hours[i] > 8 ? 1 : -1;
			if(cnt > 0)
			{
				res = i + 1;
			}
			else
			{
				if(pos.count(cnt) == 0)
				{
					pos[cnt] = i;
				}
				if(pos.count(cnt - 1) != 0)
				{
					res = max(res, i - pos[cnt - 1]);
				}
			}
		}
        return res;
    }
};
