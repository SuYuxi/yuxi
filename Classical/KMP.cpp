//KMP algorithm
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> KMP(string& txt, string& pat, vector<int>& lps);
vector<int> buildLPS(string& pat);

int main() {
	string txt, pat;
	cout << "input txt" << endl;
	cin >> txt;
	cout << "input string to find" << endl;
	cin >> pat;
	vector<int>&& lps = buildLPS(pat);
	vector<int>&& res = KMP(txt, pat, lps);
	if(!res.empty())
	{
		cout << "Subsring index is:" << endl; 
		for(int& inx : res)
		{
			cout << inx << endl;
		}
	}
	return 0;
}

vector<int> KMP(string& txt, string& pat, vector<int>& lps) {
	vector<int> res;
	for(int i = 0, k = 0; i < txt.size(); i += 1)
	{
		while(k != 0 && txt[i] != pat[k])
		{
			k = lps[k - 1];
		}
		if(txt[i] == pat[k])
		{
			k += 1;
		}
		if(k == pat.size())
		{
			res.emplace_back(i - k + 1);
			k = lps[k - 1];
		}
	}
	return res;
}

vector<int> buildLPS(string& pat) { //LPS is longest prefix suffix
	vector<int> lps(pat.size(), 0);
	int len = 0;
	for(int inx = 1; inx < pat.size(); inx += 1)
	{
		while(len != 0 && pat[inx] != pat[len])
		{
			len = lps[len - 1];
		}
		if(pat[inx] == pat[len])
		{
			len += 1;
		}
		lps[inx] = len;
	}
	return lps;
}
