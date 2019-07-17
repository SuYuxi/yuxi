class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<int> dists;
        for(vector<int>& point : points) dists.emplace_back(dist(point));
        sort(dists.begin(), dists.end(), less<int>());
        int bound = dists[K - 1];
        vector<vector<int>> res;
        for(vector<int>& point : points)
        {
            if(dist(point) <= bound) res.emplace_back(point);
        }
        return res;
    }
private:
    int dist(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

//in-place quick sort
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points, 0, points.size() - 1, K);
        vector<vector<int>> res;
        for(int i = 0; i < K; i++) res.emplace_back(points[i]);
        return res;
    }
private:
    void sort(vector<vector<int>>& points, int i, int j, int K) {
        if(i >= j) return;
        int pivot = i + (j - i) / 2;
        int inx = partition(points, i, j, pivot);
        int leftLen = inx - i + 1;
        if(K < leftLen)
        {
            sort(points, i, inx - 1, K);
        }
        else if(K > leftLen)
        {
            sort(points, inx + 1, j, K - leftLen);
        }        
    }
    
    int partition(vector<vector<int>>& points, int left, int right, int pivot) {
        int ref = dist(points[pivot]);
        swap(points[pivot], points[right]);
        int inx = left;
        for(int i = left; i < right; i++)
        {
            if(dist(points[i]) < ref)
            {
                swap(points[inx], points[i]);
                inx++;
            }
        }
        swap(points[inx], points[right]);
        return inx;
    }
    
    int dist(vector<int>& point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }
};
