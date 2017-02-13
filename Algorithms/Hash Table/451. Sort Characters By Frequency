class Solution(object):
	def frequencySort(self, s):
		d = dict()
		for c in s:
			d[c] = d.setdefault(c,0) + 1
		ans = [''] * (len(s)+1)
		for i in d:
			ans[d[i]]+=d[i]*i
		#d = sorted(d.items(),key=lambda x:(x[1],x[0]),reverse=True)
		#return ''.join([i[0] * i[1] for i in d])
		return ''.join(ans[::-1])

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char,int> freq;
		vector<string> bucket(s.size()+1, "");
		string res;

		for(char& c:s) freq[c]++;
		for(pair<char,int> it:freq) {
			int n = it.second;
			char c = it.first;
			bucket[n].append(n, c);
		}
		for(int i=s.size(); i>0; i--) {
			if(!bucket[i].empty())
				res.append(bucket[i]);
		}
		return res;
	}
};
