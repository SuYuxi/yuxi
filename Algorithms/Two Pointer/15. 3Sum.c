/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool compare (const void* a, const void* b) {
	return (*(int*)a - *(int*)b >= 0);
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
	int** ans = (int**) malloc(sizeof(int*) * numsSize * (numsSize-1) * (numsSize-2) / 6);
	*returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
	int ref, mid, right;
	for(int left = 0; left < numsSize-2; left += 1) {
		if(nums[left] + nums[left+1] + nums[left+2] > 0) break;
		if(nums[left] + nums[numsSize-2] + nums[numsSize-1] < 0) continue;
		if(left > 0 && nums[left] == nums[left-1]) continue;
		mid = left + 1, right = numsSize-1;
		while(mid < right) {
			ref = nums[left] + nums[mid] + nums[right];
			if(ref < 0) mid += 1;
			else if(ref > 0) right -= 1;
			else {
				double* p = (double*) malloc(sizeof(double) * 3);
				p[0] = nums[left];
				p[1] = nums[mid];
				p[2] = nums[right];
				ans[*returnSize] = p;	
				*returnSize += 1;
				while(mid < right && nums[mid] == nums[mid+1]) mid += 1;
				while(mid < right && nums[right] == nums[right-1]) right -= 1;
				mid += 1, right -= 1;
			}
		}
	}
	return ans;
}
