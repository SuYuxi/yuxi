class Solution {
public:
    string removeOuterParentheses(string S) {
		string res;
		int cnt = 0;
		int last = 0;
		for(int i = 0; i < S.size(); i += 1)
		{
			cnt += (S[i] == '(') ? 1 : -1;
			if(cnt == 0)
			{
				res += S.substr(last + 1, i - last - 1);
				last = i + 1;
			}
		}
		return res; 
    }
};
