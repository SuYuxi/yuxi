class Solution(object):
	def findContentChildren(self, g, s):
		g.sort()
		s.sort()	
		i, j = 0, 0
		while(i < len(s) and j < len(g)):
			if(s[i] >= g[j]):
				j += 1
			i += 1
		return j

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end(), less<int>());
		sort(s.begin(), s.end(), less<int>());
		vector<int>::iterator iter_s = s.begin();
		vector<int>::iterator iter_g = g.begin();
		while(iter_s < s.end() && iter_g < g.end()) {
			if(*iter_s >= *iter_g) iter_g += 1;
			iter_s += 1;
		}
		return iter_g - g.begin();
	}
};

var findContentChildren = function(g, s) {
	g.sort(function (a,b) {return a-b});
	s.sort(function (a,b) {return a-b});
	var inx_g = 0; var inx_s = 0;
	while(inx_g < g.length && inx_s < s.length) {
		if(g[inx_g] <= s[inx_s]) inx_g += 1;
		inx_s += 1;
	}
	return inx_g;
};
