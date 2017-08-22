class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int m = nums1.size(), n = nums2.size();	
			if(m > n) return findMedianSortedArrays(nums2, nums1);
			if(m == 0) return (nums2[(n-1)/2] + nums2[n/2]) / 2.0;
			int left = 0, right = m;
			int half = (m + n + 1) >> 1;
			while(left <= right) {
				int i = (left + right) >> 1;
				int j = half - i; 

				int L1 = (i == 0) ? INT_MIN : nums1[i-1];
				int L2 = (j == 0) ? INT_MIN : nums2[j-1];
				int R1 = (i == m) ? INT_MAX : nums1[i];
				int R2 = (j == n) ? INT_MAX : nums2[j];

				if(L1 > R2) right = i - 1;
				else if (L2 > R1) left = i + 1;	
				else return ((m+n) % 2) ? max(L1,L2) : (max(L1,L2) + min(R1,R2))/ 2.0;
			}
			return -1;
		}
};
