class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
		vector<int> res(A.size(), 0);
		int left = 0, right = A.size() - 1;
		for(int inx = A.size() - 1; inx >= 0; inx -= 1)
		{
			if(abs(A[left]) > abs(A[right]))
			{
				res[inx] = pow(A[left++], 2);
			}
			else
			{
				res[inx] = pow(A[right--], 2);
			}
		}
		return res;
	}
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
		vector<int> res;
		int left = 0, right = -1;
		for(int inx = 0; inx < A.size(); inx += 1)
		{
			if(A[inx] >= 0)
			{
				left = inx - 1;
				right = inx;
				break;
			}
		}
		while(left >= 0 && right < A.size())
		{
			if(abs(A[left]) < abs(A[right]))
			{
				res.emplace_back(pow(A[left], 2));	
				left -= 1;
			}
			else
			{
				res.emplace_back(pow(A[right], 2));
				right += 1;
			}
		}
		while(left >= 0)
		{
			res.emplace_back(pow(A[left], 2));	
			left -= 1;
		}
		while(right < A.size())
		{
			res.emplace_back(pow(A[right], 2));	
			right += 1;
		}
		return res;
    }
};
