//https://www.geeksforgeeks.org/suffix-array-set-1-introduction/
//https://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct suffix {
	int index;
	int rank[2];
	suffix() : index(0) {};
};

bool cmp(const suffix& a, const suffix& b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
};


vector<int> buildSuffixArray(const string& txt) {
	int size = txt.size();
	suffix suffixes[size];
	for(int i = 0; i < size; i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i];
		suffixes[i].rank[1] = ((i + 1) < size) ? txt[i + 1] : -1;
	}
	sort(suffixes, suffixes + size, cmp);
	int index[size];
	for(int k = 4; k < 2 * size; k *= 2)
	{
		int rank = 0;
		int preRank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		index[suffixes[0].index] = 0;
		
		for(int i = 1; i < size; i++)
		{
			if(suffixes[i].rank[0] == preRank && suffixes[i].rank[1] == suffixes[i - 1].rank[1])
			{
				suffixes[i].rank[0] = rank;
			}
			else
			{
				preRank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			index[suffixes[i].index] = i;
		}

		for(int i = 0; i < size; i++)
		{
			int next = suffixes[i].index + k / 2;
			suffixes[i].rank[1] = next < size ? suffixes[index[next]].rank[0] : -1;
		}
		sort(suffixes, suffixes + size, cmp);
	}

	vector<int> suffixArr(size);
	for(int i = 0; i < size; i++)
	{
		suffixArr[i] = suffixes[i].index;
	}
	return suffixArr;
}

//kasai's algorithm
vector<int> buildLCP(const string& txt, const vector<int>& suffixArr) { // longest common prefix
	int size = suffixArr.size();
	vector<int> LCP(size);
	int invSuff[size];
	for(int i = 0; i < size; i++)
	{
		invSuff[suffixArr[i]] = i;	
	}

	int k = 0;
	for(int i = 0; i < size; i++)
	{
		if(invSuff[i] == size - 1)
		{
			k = 0;
			continue;
		}
		int j = suffixArr[invSuff[i] + 1];
		while(i + k < size && j + k < size && txt[i + k] == txt[j + k])
		{
			k++;
		}
		LCP[invSuff[i]] = k;
		if(k > 0) k--;
	}
	return LCP;
}

int main() {
	string txt = "banana";
	vector<int> suffixArr = buildSuffixArray(S);
	vector<int> lcp = buildLCP(S, suffixArr);
};

