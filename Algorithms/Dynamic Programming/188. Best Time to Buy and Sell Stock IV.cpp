class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		int size = prices.size();
		if(size <= 1) return 0;

		if(k >= size / 2)
		{
			int maxProfit = 0;
			for(int inx = 1; inx < size; inx += 1)
			{
				if(prices[inx] > prices[inx - 1])
					maxProfit += prices[inx] - prices[inx - 1];
			}
			return maxProfit;
		}
		
		vector<int> mins(k + 1, prices[0]);
		vector<int> profits(k + 1, 0);
		for(int inx = 0; inx < size; inx += 1)
		{
			for(int tran = 1; tran <= k; tran += 1)
			{
				mins[tran] = min(mins[tran], prices[inx] - profits[tran - 1]);
				profits[tran] = max(profits[tran], prices[inx] - mins[tran]);
			}
		}
		return profits[k];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		int size = prices.size();
		if(size <= 1) return 0;

		if(k >= size / 2)
		{
			int maxProfit = 0;
			for(int inx = 1; inx < size; inx += 1)
			{
				if(prices[inx] > prices[inx - 1])
					maxProfit += prices[inx] - prices[inx - 1];
			}
			return maxProfit;
		}
		
		vector<int> profits(size, 0);
		for(int tran = 1; tran <= k; tran += 1)
		{
			vector<int> preProfits(profits);
			int minCost = prices[0];
			for(int inx = 1; inx < size; inx += 1)
			{
				profits[inx] = max(profits[inx - 1], prices[inx] - minCost);
				minCost = min(minCost, prices[inx] - preProfits[inx - 1]);
			}
		}
		return profits[size - 1];
    }
};
