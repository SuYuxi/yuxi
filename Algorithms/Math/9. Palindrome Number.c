bool isPalindrome(int x) {
	if(x < 0) { 
		return false;
	}
	int p = x, q = 0;
	while(p) {
		q = p % 10 + q * 10;
		p /= 10;
	}
	return q == x;
}
