class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int n = customers.size();
		int maxSum1= 0;
		int Sum0 = 0, Sum1 = 0;
		for(int i = 0; i < n; i++)
		{
			Sum0 += grumpy[i] ? 0 : customers[i];
			Sum1 += grumpy[i] ? customers[i] : 0;
			if(i >= X)
			{
				Sum1 -= grumpy[i - X] ? customers[i - X] : 0;
			}
			maxSum1 = max(maxSum1, Sum1);
		}
		return maxSum1 + Sum0;
    }
};
