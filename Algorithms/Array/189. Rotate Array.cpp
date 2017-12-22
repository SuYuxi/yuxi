class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		int count = 0;
		int length = nums.size();
		for(int start = 0; count < length; ++start) {
			int current = start;
			int pre = nums[start];
			int next, temp;
			do {
				next = (current + k) % length;
				temp = nums[next];
				nums[next] = pre;
				pre = temp;
				current = next;
				++count;
			}
			while(start != current);
		}
    }
};
