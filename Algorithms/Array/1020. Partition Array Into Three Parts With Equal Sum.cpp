class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
		int total = 0;
		for(int& a : A)
		{
			total += a;
		}
		if(total % 3 != 0) return false;
		int parts = 0, sum = 0;
		for(int& a : A)
		{
			sum += a;
			if(sum == total / 3)
			{
				parts += 1;
				sum = 0;
			}
		}
		return parts == 3 ? true : false;
    }
};
