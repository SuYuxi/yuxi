class Solution {
public:
    string convertToTitle(int n) {
		std::string res;
		int remainder = 0;
		while(n != 0) {
			remainder = (--n) % 26;
			res = (char)(remainder + 65) + res;
			n /= 26;
		}
		return res;
    }
};
