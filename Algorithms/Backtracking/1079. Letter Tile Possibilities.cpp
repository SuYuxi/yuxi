class Solution {
public:
    int numTilePossibilities(string tiles) {
		vector<int> cnt(26, 0); 
		for(char& t : tiles)
		{
			cnt[t - 'A']++;
		}
		return backtracking(cnt);
    }

private:
	int backtracking(vector<int>& cnt) {
		int sum = 0;
		for(int i = 0; i < 26; i++)
		{
			if(cnt[i] != 0)
			{
				sum++;
				cnt[i]--;
				sum += backtracking(cnt);
				cnt[i]++;
			}
		}
		return sum;
	}
};
