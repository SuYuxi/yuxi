class Solution {
public:
    string removeDuplicates(string S) {
		vector<char> stack;
		for(char& c : S)
		{
			if(!stack.empty() && c == stack.back())
			{
				stack.pop_back();
			}
			else
			{
				stack.emplace_back(c);
			}
		}
		string ans;
		for(char& c : stack)
		{
			ans.push_back(c);
		}
		return ans;
    }
};
