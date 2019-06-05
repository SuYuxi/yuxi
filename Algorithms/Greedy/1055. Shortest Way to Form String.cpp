class Solution {
public:
    int shortestWay(string source, string target) {
		unordered_map<char, vector<int>> index; 
		int n = source.size(), m = target.size();
		for(int i = 0; i < n; i++)
		{
			index[source[i]].emplace_back(i);
		}
		int ans = 1;
		for(int i = 0, j = -1; i < m;)
		{
			char c = target[i];
			if(index.count(c) == 0) return -1;
			bool found = false;
			for(int& inx : index[c])
			{
				if(inx > j)
				{
					j = inx;
					found = true;
					break;
				}
			}
			if(!found)
			{
				j = -1;
				ans++;
			}
			else
			{
				i++;
			}
		}
		return ans;
    }
};
