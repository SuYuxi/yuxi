class Solution {
public:
    bool isStrobogrammatic(string num) {
		int n = num.size();
		int l = (n - 1) / 2, r = n / 2;
		while(l >= 0 && r < n)
		{
			if(hash.count(num[l]) == 0 || hash[num[l]] != num[r]) return false;
			l--;
			r++;
		}
		return true;
    }
private:
	unordered_map<char, char> hash = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'9', '6'}, {'8', '8'}};
};
