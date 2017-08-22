int maxArea(int* height, int heightSize) {
		int left = 0, right = heightSize-1;
		int ans = 0;
		int L, area;
		while(left < right) {
			L = right - left;	
			if(height[left] < height[right]) {
				area = height[left] * L;
				left += 1;
			}
			else {
				area = height[right] * L;
				right -= 1;
			}
			if(ans < area) ans = area;
		}
       return ans; 
}
