//Segment Tree
//range min query
//array implementation
#include <vector>
#include <cmath>
#include <numeric_limits>

using namespace std;
class SegmentTree{
public:
	void build(const vector<int>& A) {
		size = A.size();
		segmentTree = vector<int>(2 * size, INT_MAX);
		for(int i = 0; i < size; i++)
		{
			update(i, A[i]);
		}
	};

	void update(int inx, int value) {
		int i = size - 1 + inx;
		segmentTree[i] = value;
		while(i > 0)
		{
			i = (i - 1) / 2;
			segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
		}
	};

	int query(int start, int end) {
		return query(start, end, 0, size - 1, 0);
	};

private:
	int query(int start, int end, int left, int right, int inx) {
		if(right < start || end < left) return INT_MAX; 
		if(start <= left && right <= end) return segmentTree[inx];
		int mid = (left + right) / 2;
		return min(query(start, end, left, mid, inx * 2 + 1), query(start, end, mid + 1, right, inx * 2 + 2));
	}

	vector<int> segmentTree;
	int size;

};
