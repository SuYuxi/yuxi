//outside-in
class Solution {
public:
    vector<int> diStringMatch(string S) {
		vector<int> res;
		int left = 0, right = S.size();
		for(char& s : S)
		{
			switch(s)
			{
				case 'I':
					res.emplace_back(left++);
					break;
				case 'D':
					res.emplace_back(right--);
					break;
			}
		}
		res.emplace_back(left);
		return res;
    }
};

//inside-out
class Solution {
public:
    vector<int> diStringMatch(string S) {
		int left = count(S.begin(), S.end(), 'D'), right = left;
		vector<int> res = {left};
		for(char& s : S)
		{
			switch(s)
			{
				case 'D':
					res.emplace_back(--left);
					break;
				case 'I':
					res.emplace_back(++right);
					break;
			}
		}
		return res;
    }
};
