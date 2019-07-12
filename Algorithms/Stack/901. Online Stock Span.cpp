class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
		int count = 1;	
		while(!prices.empty() && prices.back() <= price)
		{
			count += counts.back();
			counts.pop_back();
			prices.pop_back();
		}
		prices.emplace_back(price);
		counts.emplace_back(count);
		return count;
    }

private:
	vector<int> prices;
	vector<int> counts;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
