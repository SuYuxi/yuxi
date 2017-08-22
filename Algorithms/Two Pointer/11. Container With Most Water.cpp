class Solution {
public:
    int maxArea(vector<int>& height) {
		int left = 0, right = height.size()-1;
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
};
