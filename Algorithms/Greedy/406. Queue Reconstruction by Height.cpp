//in increasing sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		int n = people.size();
		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){ return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        vector<vector<int>> queue(n, vector<int>());
		for(int i = 0; i < n; i++)
		{
			int inx = 0;
			for(int j = 0; j < n; j++)
			{
				if(queue[j].empty())
				{
					if(inx == people[i][1])
					{
						queue[j] = people[i];
						break;
					}
					inx++;
				}
				else if(queue[j][0] == people[i][0]) inx++;
			}
		}
		return queue;
    }
};

//in decreasing sort
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];});
		vector<vector<int>> queue;
		for(vector<int>& p : people)
		{
			queue.insert(queue.begin() + p[1], p);
		}
		return queue;
	}
};
