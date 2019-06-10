class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
		int n1 = str1.size(), n2 = str2.size();
		int T = gcd(n1, n2);
		string X = str1.substr(0, T);
		for(int i = 0; i < max(n1, n2); i += T)
		{
			if(i < n1 && str1.compare(i, T, X)) return "";
			if(i < n2 && str2.compare(i, T, X)) return "";
		}
		return X;
    }
	
	int gcd(int a, int b) {
		int t = 1;
		while(t != 0)
		{
			t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
};
