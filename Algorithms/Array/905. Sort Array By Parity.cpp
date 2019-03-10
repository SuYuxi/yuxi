class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		int left = 0, right = A.size() - 1;
		vector<int> res(A.size(), 0);
		for(int& num : A)
		{
			if(num % 2 == 1) {
				res[right--] = num;
			}
			else
			{
				res[left++] = num;
			}
		}
		return res;
    }
};
