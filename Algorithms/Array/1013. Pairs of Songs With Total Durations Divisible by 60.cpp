class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> hash(60, 0);
		int res = 0;
		for(int& t : time)
		{
			res += hash[(60 - t % 60) % 60];
			hash[t % 60] += 1;
		}
		return res;
    }
};
