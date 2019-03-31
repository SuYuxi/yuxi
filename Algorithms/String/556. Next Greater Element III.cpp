class Solution {
public:
    int nextGreaterElement(int n) {
		vector<int> digits; //store digits into vector
		for(char& c : to_string(n))
		{
			digits.emplace_back(c - '0');
		}

		int i;//find first element that break decreasing array
		for(i = digits.size() - 1; i > 0; i -= 1)
		{
			if(digits[i - 1] < digits[i])
				break;
		}
		//i - 1 is the first element that break decreasing array

		if(i == 0) return -1;//if no element found

		int minInx = i; //find smallest element bigger than value of i - 1 in the right side of i;
		for(int inx = i + 1; inx < digits.size(); inx += 1)
		{
			if(digits[i - 1] < digits[inx] && digits[inx] <= digits[minInx])
			{
				minInx = inx;
			}
		}
		swap(digits[i - 1], digits[minInx]);//swap i - 1 and smallest bigger element

		sort(digits.begin() + i, digits.end());//sort right part of i in ascending
		long res = 0;
		for(int& num : digits)
		{
			res = res * 10 + num;
		}
		return res <= INT_MAX ? (int)res: -1;
    }
};
