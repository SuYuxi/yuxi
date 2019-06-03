struct Pair {
	int dist;	
	int wInx;
	int bInx;
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int n = workers.size(), m = bikes.size();
		vector<Pair> pairs;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				pairs.emplace_back(Pair{getDist(workers[i], bikes[j]), i, j});
			}
		}
		sort(pairs.begin(), pairs.end(), 
		[](Pair& p1, Pair& p2)
		{
			if(p1.dist != p2.dist) return p1.dist < p2.dist;
			if(p1.wInx != p2.wInx) return p1.wInx < p2.wInx;
			return p1.bInx < p2.bInx;
		});
		vector<bool> visitedB(m, false);
		vector<int> res(n, -1);
		int cnt = 0;
		for(Pair& p : pairs)
		{
			if(res[p.wInx] == -1 && !visitedB[p.bInx])
			{
				res[p.wInx] = p.bInx;
				visitedB[p.bInx] = true;
				cnt++;
			}
			if(cnt == n) break;
		}
		return res;
    }
	
private:
	int getDist(vector<int>& A, vector<int>& B) {
		return abs(A[0] - B[0]) + abs(A[1] - B[1]);
	}
};
