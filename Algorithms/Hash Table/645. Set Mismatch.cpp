#include <stdlib.h> 

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		int dup = -1, missing = -1;
		for(int &num : nums) {
			if(nums[abs(num) - 1] < 0) {
				dup = abs(num);
			}
			else {
				nums[abs(num) - 1] *= -1;
			}
		}
		for(int i = 0;i < nums.size();i += 1) {
			if(nums[i] > 0) {
				missing = i + 1;
				break;
			}
		}
		vector<int> res(2);
		res[0] = dup;
		res[1] = missing;
		return res;	
    }
};
