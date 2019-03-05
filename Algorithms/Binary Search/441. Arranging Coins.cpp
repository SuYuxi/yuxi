class Solution {
public:
    int arrangeCoins(int n) {
		//return floor((sqrt(8 * long(n)+ 1) - 1) / 2);
		return (sqrt(8 * long(n)+ 1) - 1) / 2);
    }
};
