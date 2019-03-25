//hash
class Solution {
public:
    bool queryString(string S, int N) {
		unordered_set<string> visited;
		for(int num = 1; num <= N; num += 1)
		{
			string s = std_to_bin(num);
			int len = s.size();
			bool flag = false;
			for(int i = 0; i < S.size() - len + 1; i += 1)
			{
				string sub = S.substr(i, len);	
				visited.insert(sub);
				if(visited.count(s) != 0 || sub == s)
				{
					flag = true;
					break;
				}
			}
			if(!flag) return false;
		}
		return true; 
    }

	std::string std_to_bin(int num) {
		std::string str;
		while(num > 0)
		{
			str.push_back('0' + (num & 1));
			num >>= 1;
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

//straight forward
class Solution {
public:
    bool queryString(string S, int N) {
		for(int i = N; i > N / 2; i -= 1)
		{
			string b = bitset<32>(i).to_string();
			if(S.find(b.substr(b.find("1"))) == string::npos)
				return false;
		}
		return true;
	}
};
