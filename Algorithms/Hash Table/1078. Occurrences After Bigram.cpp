class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
		string buffer = "";
		vector<string> ans;
		string prev2, prev;
		for(char& c : text)
		{
			if(c != ' ')
			{
				buffer.push_back(c);
			}
			else
			{
				if(prev2 == first && prev == second) ans.emplace_back(buffer);
				prev2 = prev;
				prev = buffer;
				buffer.clear();
			}
		}
		if(prev2 == first && prev == second) ans.emplace_back(buffer);
		return ans;
    }
};
