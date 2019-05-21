#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
		if(words.empty()) return vector<vector<string>>();
		prefixs.clear();
		size = words[0].size();
		for(int i = 0; i < words.size(); i++)
		{
			string word = words[i];
			for(int len = 0; len < size; len++)
			{
				prefixs[word.substr(0, len)].emplace_back(word);
			}
		}
		vector<string> square;
		vector<vector<string>> squares;
		backtracking(words, square, squares);
		return squares;
    }

private:
	unordered_map<string, vector<string>> prefixs;
	int size;

	void backtracking(vector<string>& words, vector<string>& square, vector<vector<string>>& squares) {
		if(square.size() == size)
		{
			squares.emplace_back(square);
			return;
		}
		int k = square.size();
		string prefix;
		for(int i = 0; i < square.size(); i++)
		{
			prefix.push_back(square[i][k]);
		}
		for(string& word : prefixs[prefix])
		{
			square.emplace_back(word);
			backtracking(words, square, squares);
			square.pop_back();
		}
	}
};
