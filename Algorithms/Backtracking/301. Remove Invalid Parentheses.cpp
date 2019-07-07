//traditional and easy to understand
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		validParentheses.clear();
		str = s;
		int leftRem = 0, rightRem = 0;
		for(char& c : s)
		{
			if(c == '(')
			{
				leftRem++;
			}
			else if(c == ')')
			{
				if(leftRem > 0)
				{
					leftRem--;
				}
				else
				{
					rightRem++;
				}
			}
		}
		string expression = "";	
		backtracking(0, 0, 0, leftRem, rightRem, expression);
		vector<string> res;
		for(auto i : validParentheses)
		{
			res.emplace_back(i);
		}
		return res;
    }
	
private:
	set<string> validParentheses;
	string str;
	void backtracking(int index, int leftCnt, int rightCnt, int leftRem, int rightRem, string& expression) {
		if(index == str.size())
		{
			if(leftRem == 0 && rightRem == 0)
				validParentheses.insert(expression);
		}
		else
		{
			char c = str[index];
			if((c == '(' && leftRem > 0) || (c == ')' && rightRem > 0))
			{
				backtracking(index + 1, leftCnt, rightCnt, leftRem - (c == '(' ? 1 : 0), rightRem - (c == ')' ? 1 : 0), expression);
			}
			expression.push_back(c);
			if(c != '(' && c != ')')
			{
				backtracking(index + 1, leftCnt, rightCnt, leftRem, rightRem, expression);
			}
			else if(c == '(')
			{
				backtracking(index + 1, leftCnt + 1, rightCnt, leftRem, rightRem, expression);
			}
			else if(c == ')' && rightCnt < leftCnt)
			{
				backtracking(index + 1, leftCnt, rightCnt + 1, leftRem, rightRem, expression);
			}
			expression.pop_back();
		}
	}
};

//faster
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		validParentheses.clear();
		vector<char> brackets = {'(', ')'};
		remove(0, 0, s, brackets);
		return validParentheses;
	}
private:
	vector<string> validParentheses;
	void remove(int last_i, int last_j, string str, vector<char> brackets) {
		for(int cnt = 0, i = last_i; i < str.size(); i++)
		{
			if(str[i] == brackets[0]) cnt++;
			else if(str[i] == brackets[1]) cnt--;
			if(cnt < 0)
			{
				for(int j = last_j; j <= i; j++)
				{
					if(str[j] == brackets[1] && (j == last_j || str[j - 1] != brackets[1]))
					{
						remove(i, j, str.substr(0, j) + str.substr(j + 1, str.size() - j), brackets);
					}
				}
				return;
			}
		}
		reverse(str.begin(), str.end());
		if(brackets[0] == '(')
		{
			reverse(brackets.begin(), brackets.end());
			remove(0, 0, str, brackets);
		}
		else
		{
			validParentheses.emplace_back(str);
		}
	}
};
