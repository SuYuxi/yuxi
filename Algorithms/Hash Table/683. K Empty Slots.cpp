const int INF = 1e9;
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
		int size = flowers.size();
		vector<int> days(size);
		for(int i = 0; i < size; i++)
		{
			days[flowers[i] - 1] = i + 1;
		}
		int res = INF;
		int left = 0, right = k + 1;
		while(right < size)
		{
			bool flag = true;
			for(int i = left + 1; i < right; i++)
			{
				if(days[i] < days[left] || days[i] < days[right])
				{
					left = i;
					right = i + k + 1;
					flag = false;
					break;
				}
			}
			if(flag)
			{
				res = min(res, max(days[left], days[right]));
				left = right;
				right = right + k + 1;
			}
		}
		if(res == INF) res = -1;
		return res;
    }
};
