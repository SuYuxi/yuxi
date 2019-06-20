class Solution {
public:
    string numberToWords(int num) {
		int base = 1000;
		string res = helper(num % base);
		num /= base;

		int inx = 0;
		while(num != 0)
		{
			if(num % base != 0)
			{
				res = helper(num % base) + " " + units[inx] + res;
			}
			num /= base;
			inx++;
		}
		return res.empty() ? "Zero" : res.substr(1);
    }
private:
	string helper(int num) {
		if(num == 0) return "";
		if(num < 20) return " " + less20[num];
		if(num < 100) return " " + tens[num / 10] + helper(num % 10);
		if(num < 1000) return " " + less20[num / 100] + " Hundred" + helper(num % 100);
		return "";
	}

	vector<string> less20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	
	vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; 

	vector<string> units = {"Thousand", "Million", "Billion"};
};

