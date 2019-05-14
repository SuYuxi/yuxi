class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
		if(S.empty()) return "";
		string ans;
		for(int i = S.size() - 1, cnt = 0; i >= 0; i--)
		{
			if(S[i] != '-')
			{
				if(cnt % (K + 1) == K)
				{
					ans.push_back('-');
					cnt++;
				}
				if(S[i] <= 'z' && S[i] >= 'a')
				{
					ans.push_back(S[i] - 'a' + 'A');
				}
				else
				{
					ans.push_back(S[i]);
				}
				cnt++;
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};
