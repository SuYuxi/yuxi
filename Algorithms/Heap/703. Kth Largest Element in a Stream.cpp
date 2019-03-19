class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
		K = k;
		for(int& num : nums)
		{
			heap.emplace(num);
			if(heap.size() > k) heap.pop();
		}
    }
    
    int add(int val) {
		heap.emplace(val);
		if(heap.size() > K) heap.pop();
		return heap.top();
    }
private:
	priority_queue<int, vector<int>, greater<int>> heap;
	int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
