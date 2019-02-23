class Solution {
public:
    int findNthDigit(int n) {
		long base = 9;
		int digits = 1;
		while(n - base * digits > 0)
		{
			n -= base * digits;
			base *= 10;
			digits += 1;
		}

		int numOffset = (n - 1) / digits;
		int index = (n - 1) % digits;
		int num = pow(10, digits - 1) + numOffset;
		for(int i = index; i < digits - 1; i += 1)
		{
			num /= 10;
		}
		return num % 10;
		
		//return to_string(pow(10, digits - 1) + numOffset)[index] - '0'; 
    }
};
