//left bound and right bound
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		int modulo = 1e9 + 7;
		int n = A.size();
		vector<int> left(n, 1);
		vector<int> right(n, 1);
		vector<int> stack; //store index
		for(int i = 0; i < n; i++)
		{
			while(!stack.empty() && A[i] <= A[stack.back()])
			{
				stack.pop_back();
			}
			left[i] = stack.empty() ? i + 1 : i - stack.back();
			stack.emplace_back(i);
		}

		stack.clear();
		for(int i = n - 1; i >= 0; i--)
		{
			while(!stack.empty() && A[i] < A[stack.back()])
			{
				stack.pop_back();
			}
			right[i] = stack.empty() ? n - i : stack.back() - i;
			stack.emplace_back(i);
		}

		int result = 0;
		for(int i = 0; i < n; i++)
		{
			result += (A[i] * left[i] * right[i]) % modulo;
			result %= modulo;
		}
		return result;
    }
};

//single round
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
		int modulo = 1e9 + 7;
		int n = A.size();
		int result = 0;
		vector<int> stack;
		int j, k;
		for(int i = 0; i <= n; i++)
		{
			while(!stack.empty() && A[stack.back()] > (i == n ? INT_MIN : A[i]))
			{
				j = stack.back();	
				stack.pop_back();
				k = stack.empty() ? -1 : stack.back();

				result += A[j] * (i - j) * (j - k) % modulo;
				result %= modulo;
			}
			stack.emplace_back(i);
		}

		return result;
	}
};
