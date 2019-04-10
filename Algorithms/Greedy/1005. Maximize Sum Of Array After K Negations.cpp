#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
		if(A.empty()) return 0;
        sort(A.begin(), A.end(), less<int>());
		for(int i = 0; K > 0 && i < A.size() && A[i] < 0; i += 1, K -= 1)
		{
			A[i] = -A[i];
		}
		return accumulate(A.begin(), A.end(), 0) - (K % 2) * 2 * (*min_element(A.begin(), A.end())); 
    }
};
