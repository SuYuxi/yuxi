class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
		for(int num = 1; num < 7; num += 1)
		{
			bool flag = true;
			int a = 0, b = 0;
			for(int inx = 0; inx < A.size(); inx += 1)
			{
				if(A[inx] != num && B[inx] != num)
				{
					flag = false;
					break;
				}
				if(A[inx] == num) a += 1;
				if(B[inx] == num) b += 1;
			}
			if(flag)
			{
				return A.size() - max(a, b);
			}
		}
		return  -1;
    }
};
