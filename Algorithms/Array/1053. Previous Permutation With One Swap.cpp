class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
		int i = A.size() - 2;
		while(i >= 0 && A[i] <= A[i + 1]) i--;
		if(i < 0) return A;
		int j = A.size() - 1;
		while(A[i] <= A[j]) j--;
		while(A[j - 1] == A[j]) j--;
		swap(A[i], A[j]);
		return A;
    }
};
