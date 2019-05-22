//stack
class Solution {
public:
    bool backspaceCompare(string S, string T) {
		vector<char> v1, v2;
		for(char& c : S)
		{
			if(c != '#')
			{
				v1.emplace_back(c);
			}
			else if(!v1.empty())
			{
				v1.pop_back();
			}
		}
		for(char& c : T)
		{
			if(c != '#')
			{
				v2.emplace_back(c);
			}
			else if(!v2.empty())
			{
				v2.pop_back();
			}
		}
		return v1 == v2;
    }
};
//two pointers
class Solution {
public:
    bool backspaceCompare(string S, string T) {
		int i = S.size() - 1, j = T.size() - 1;
		int skipS = 0, skipT = 0;
		while(i >= 0 || j >= 0)
		{
			while(i >= 0)
			{
				if(S[i] == '#') { skipS++; }
				else if(skipS != 0) { skipS--; }
				else { break; }
				i--;
			}
			while(j >= 0)
			{
				if(T[j] == '#') { skipT++; }
				else if(skipT != 0) { skipT--; }
				else { break; }
				j--;
			}
			if(i >= 0 && j >= 0 && S[i] != T[j]) return false;
			if((i >= 0) != (j >= 0)) return false;
			i--;
			j--;
		}
		return true;
	}
};
