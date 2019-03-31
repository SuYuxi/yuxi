class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
		int num = 0;
		vector<bool> res;
		for(int& bit : A)
		{
			num = ((num << 1) + bit) % 10;
			res.emplace_back(num % 5 == 0);
		}
		return res;
    }
};
