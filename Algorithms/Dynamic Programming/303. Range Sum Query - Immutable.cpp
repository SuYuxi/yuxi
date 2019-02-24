class NumArray {
public:
    NumArray(vector<int> nums) {
		int sum = 0;
		for(int &num : nums)
		{
			sum += num;
			sumVec.emplace_back(sum);
		}
    }
    
    int sumRange(int i, int j) {
		return sumVec[j+1] - sumVec[i];
    }

private:
	vector<int> sumVec{0};
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
