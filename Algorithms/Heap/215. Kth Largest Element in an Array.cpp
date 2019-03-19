class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>()); 
		return nums[k-1];
    }
};

//maxHeap
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, less<int>> maxHeap(nums.begin(), nums.end());
		for(int i = 0; i < k - 1; i += 1)
		{
			maxHeap.pop();
		}
		return maxHeap.top();
		
	}
};

//minHeap
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		for(int& num : nums)
		{
			minHeap.emplace(num);
			if(minHeap.size() > k) minHeap.pop();
		}
		return minHeap.top();
		
	}
};

//Quicksort
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		int pivot;
		while(true)
		{
			pivot = partition(nums, left, right);	
			if(pivot == k - 1) return nums[k - 1];
			if(pivot < k - 1) left = pivot + 1;
			else if(pivot > k - 1) right = pivot - 1;
		}
	}
	int partition(vector<int>& nums, int left, int right) {
		int pivot = left + (right - left) / 2;
		int val = nums[pivot];
		swap(nums[pivot], nums[right]);
		for(int inx = left; inx < right; inx += 1)
		{
			if(nums[inx] > val)
			{
				swap(nums[inx], nums[left]);
				left += 1;
			}
		}
		swap(nums[left], nums[right]);
		return left;
	}
};

//Completed Quicksort
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		quicksort(nums, 0, nums.size() - 1);
		return nums[k-1];
	}
	void quicksort(vector<int>& nums, int left, int right) {
		if(left >= right) return;
		int pivot = partition(nums, left, right);
		quicksort(nums, left, pivot - 1);
		quicksort(nums, pivot + 1, right);
	}
	int partition(vector<int>& nums, int left, int right) {
		int pivot = left + (right - left) / 2;
		int val = nums[pivot];
		swap(nums[pivot], nums[right]);
		for(int inx = left; inx < right; inx += 1)
		{
			if(nums[inx] > val)
			{
				swap(nums[inx], nums[left]);
				left += 1;
			}
		}
		swap(nums[left], nums[right]);
		return left;
	}
};

//Heap sort
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		buildMaxHeap(nums);
		for(int i = 0; i < k - 1; i += 1)
		{
			swap(nums[0], nums.back());
			nums.pop_back();
			maxHeapify(nums, 0);
		}
		return nums[0];	
	}

	void maxHeapify(vector<int>& nums, int i) {
		int left = (i << 1) + 1, right = (i << 1) + 2;
		int largest = i;
		if(left < nums.size() && nums[left] > nums[largest])
		{
			largest = left ;
		}
		if(right < nums.size() && nums[right] > nums[largest])
		{
			largest = right;
		}
		if(largest != i)
		{
			swap(nums[i], nums[largest]);
			maxHeapify(nums, largest);
		}
	}

	void buildMaxHeap(vector<int>& nums) {
		for(int inx = (nums.size() >> 1) - 1; inx >= 0; inx -=1) {
			maxHeapify(nums, inx);
		}
	}
};
