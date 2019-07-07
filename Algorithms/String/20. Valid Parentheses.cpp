class Solution {
public:
    bool isValid(string s) {
		unordered_map<char, char> mapping({{'}', '{'}, {')', '('}, {']', '['}});
		unordered_set<char> leftBracket({'(', '[', '{'});
		vector<char> stack;
		for(char& c : s)
		{
			if(leftBracket.count(c) != 0)
			{
				stack.emplace_back(c);
			}
			else
			{
				if(stack.empty() || stack.back() != mapping[c]) return false;
				stack.pop_back();
			}
		}
		return stack.empty();
    }
};

