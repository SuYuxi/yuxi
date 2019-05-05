//https://www.jianshu.com/p/91f2c503e62f?utm_campaign=maleskine&utm_content=note&utm_medium=seo_notes&utm_source=recommendation
//Segment Tree
//range min query
//array implementation
#include <vector>
#include <cmath>
#include <numeric_limits>

using namespace std;
class SegmentTree{
public:
	SegmentTree(const vector<int>& A) {
		size = A.size();
		if(size > 0)
		{
			segmentTree = vector<int>(4 * size, INT_MAX);
			build(A, 0, size - 1, 0);
		}
	}
	void build(const vector<int>& A, int start, int end, int inx) {
		if(start == end)
		{
			segmentTree[inx] = A[start];
			return;
		}
		int mid = (start + end) / 2;
		build(A, start, mid, 2 * inx + 1);
		build(A, mid + 1, end, 2 * inx + 2);
		segmentTree[inx] = min(segmentTree[2 * inx + 1], segmentTree[2 * inx + 2]);
	};

	void update(int i, int value) {
		update(0, size - 1, i, value, 0);
	};

	int query(int i, int j) {
		return query(0, size - 1, i, j, 0);
	};

private:
	void update(int start, int end, int i, int value, int inx) {
		if(start == end)
		{
			segmentTree[inx] = value;
			return;
		}
		int mid = (start + end) / 2;
		if(i <= mid)
		{
			update(start, mid, i, value, 2 * inx + 1);
		}
		else
		{
			update(mid + 1, end, i, value, 2 * inx + 2);
		}
		segmentTree[inx] = min(segmentTree[2 * inx + 1], segmentTree[2 * inx + 2]);
	}

	int query(int start, int end, int i, int j, int inx) {
		if(start > j || end < i) return INT_MAX;
		if(i <= start && j >= end) return segmentTree[inx];
		int mid = (start + end) / 2;
		return min(query(start, mid, i, j, 2 * inx + 1), query(mid + 1, end, i, j, 2 * inx + 2)); 
	}

	vector<int> segmentTree;
	int size;
};
