class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
		for(int inx = 2; inx < A.size(); inx += 1)
		{
			if(A[inx] == A[inx - 1] || A[inx] == A[inx - 2]) return A[inx];
		}
		return A[0]; 
    }
};
