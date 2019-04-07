#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> res;
		for(string& query : queries)
		{
			res.emplace_back(match(query, pattern));
		}
		return res;
    }

private:
	bool match(const string& query, const string& pattern)
	{
		int N = query.size(), M = pattern.size();
		int i = 0, j = 0;
		while(i < N && j < M)
		{
			if(query[i] == pattern[j])
			{
				i += 1;
				j += 1;
			}
			else if(query[i] < 'a' || query[i] > 'z')
			{
				return false;	
			}
			else
			{
				i += 1;
			}
		}
		if(j < M) return false;
		while(i < N)
		{
			if(query[i] < 'a' || query[i] > 'z') return false;
			i += 1;
		}

		return true;
	}
};
