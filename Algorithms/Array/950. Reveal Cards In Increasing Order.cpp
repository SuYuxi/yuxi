class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
		std::sort(deck.begin(), deck.end());
		std::vector<int> res(deck.size(), 0);
		std::deque<int> index(deck.size(), 0);
		for(int i = 0; i < deck.size(); i += 1)
		{
			index[i] = i;
		}
		for(int& card : deck)
		{
			res[index.front()] = card;
			index.pop_front();
			index.emplace_back(index.front());
			index.pop_front();
		}

		return res; 
    }
};
