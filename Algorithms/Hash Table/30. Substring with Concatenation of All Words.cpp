class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int wordNum = words.size(), lenS = s.size();
		if(lenS == 0 || wordNum == 0) return res;
		int wordSize = words[0].size();
		unordered_map<string, int> hash, curHash;
		for(string& word : words)
		{
			hash[word] += 1;
		}
		for(int start = 0; start < wordSize; start += 1)
		{
			int left = start, right = start;
			int count = 0;
			while(right + wordSize - 1 < lenS)
			{
				string strR = s.substr(right, wordSize);
				right += wordSize;
				if(hash.count(strR))
				{
					curHash[strR] += 1;
					count += 1;
					while(curHash[strR] > hash[strR])
					{
						string strL = s.substr(left, wordSize);
						curHash[strL] -= 1;
						left += wordSize;
						count -= 1;
					}
					if(count == wordNum)
					{
						res.emplace_back(left);
						string strTmp = s.substr(left, wordSize);
						curHash[strTmp] -= 1;
						left += wordSize;
						count -= 1;
					}
				}
				else
				{
					left = right;
					count = 0;
					curHash.clear();
				}
			}
			curHash.clear();
		}
		return res;
    }
};
