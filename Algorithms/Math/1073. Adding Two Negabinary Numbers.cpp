class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		vector<int> res;
		int n1 = arr1.size() - 1, n2 = arr2.size() - 1;
		int carry = 0;
		while(n1 >= 0 || n2 >= 0 || carry != 0)
		{
			if(n1 >= 0) carry += arr1[n1--];
			if(n2 >= 0) carry += arr2[n2--];
			res.emplace_back(carry & 1);
			carry = -(carry >> 1);
		}
		while(res.size() > 1 && res.back() == 0) res.pop_back();
		reverse(res.begin(), res.end());
		return res;
    }
};
