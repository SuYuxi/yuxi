int lengthOfLongestSubstring(char* s) {
	int charset[128];	
	int start = 0, right = 0, maxLength = 0;
	for(int i = 0; i < 128; i += 1) {
		charset[i] = -1;
	}
	while(*s) {
		if(charset[*s] >= start) {
			start = charset[*s] + 1;
		}
		else if(right - start + 1 > maxLength) {
			maxLength = right - start + 1;
		}
		charset[*s] = right;
		right += 1;
		s += 1;
	}
   	return maxLength; 
}
