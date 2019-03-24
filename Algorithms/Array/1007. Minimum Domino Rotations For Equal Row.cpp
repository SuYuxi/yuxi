class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
		int size = A.size();
		for(int i = 0, a = 0, b = 0; i < size && (A[i] == A[0] || B[i] == A[0]); i += 1)
		{
			if(A[i] != A[0]) a += 1;
			if(B[i] != A[0]) b += 1;
			if(i == size - 1) return min(a, b);
		}

		for(int i = 0, a = 0, b = 0; i < size && (A[i] == B[0] || B[i] == B[0]); i += 1)
		{
			if(A[i] != B[0]) a += 1;
			if(B[i] != B[0]) b += 1;
			if(i == size - 1) return min(a, b);
		}
		return -1;
	}
};

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
		int top = A[0], btm = B[0], topA = 0, topB = 0, btmA = 0, btmB = 0;
		for(int inx = 0; inx < A.size(); inx += 1)
		{
			if(A[inx] != top && B[inx] != top) top = 0;
			if(B[inx] != btm && A[inx] != btm) btm = 0;
			topA += A[inx] == top;
			topB += B[inx] == top;
			btmA += A[inx] == btm;
			btmB += B[inx] == btm;
		}
		return top || btm ? min(A.size() - max(topA, btmA), A.size() - max(topB, btmB)): -1;
    }
};
