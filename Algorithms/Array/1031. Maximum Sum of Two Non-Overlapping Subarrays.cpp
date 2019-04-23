class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		return max(maxSumOrderedTwo(A, L, M), maxSumOrderedTwo(A, M, L));
    }
private:
	int maxSumOrderedTwo(vector<int>& A, int L, int M) {
		int curL = 0, curM = 0;
		for(int i = 0; i < L; i++)
		{
			curL += A[i]; 
		}
		int maxL = curL;
		for(int i = L; i < L + M; i++)
		{
			curM += A[i]; 
		}
		int maxTwo = maxL + curM;
		for(int i = L + M; i < A.size(); i++)
		{
			curM += A[i] - A[i - M];
			curL += A[i - M] - A[i - M - L];
			maxL = max(maxL, curL);
			maxTwo = max(maxTwo, maxL + curM);
		}
		return maxTwo;
	}
};
