//DP
class Solution {
public:
    int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(int i = 1; i <= n; i += 1)
		{
			for(int j = 1; j * j <= i; j += 1)
			{
				dp[i] = min(dp[i], dp[i - j * j] + 1);
			}
		}
		return dp[n];
	}
};

//Breadth first search
class Solution {
public:
    int numSquares(int n) {
		vector<int> squares;
		vector<int> visited(n + 1, 0);
		queue<int> q;
		for(int i = 1, square = 0; i <= sqrt(n); i += 1)
		{
			square = i * i;
			squares.emplace_back(square);
			q.emplace(square);
			visited[square] = 1;
		}

		if(squares.back() == n) return 1;

		while(!q.empty())
		{
			int qSize = q.size();
			for(int i = 0, cur = 0; i < qSize; i += 1)
			{
				cur = q.front();
				q.pop();
				for(int& square : squares)
				{
					int sum = cur + square;
					if(sum == n) return visited[cur] + 1;
					if(sum < n && visited[sum] == 0)
					{
						visited[sum] = visited[cur] + 1;
						q.emplace(sum);
					}
				}
			}
		}
		return -1;
	}
};

//Lagrange's Four Square theorem
//Legendre's three-square theorem
class Solution {
public:
    int numSquares(int n) {
		if(isSquare(n)) return 1;

		int sqrtN = sqrt(n);
		while(sqrtN > 0)
		{
			if(isSquare(n - pow(sqrtN, 2)))	return 2;
			sqrtN -= 1;
		}

		while((n & 3) == 0) n >>= 2;
		if((n & 7) == 7) return 4;

		
		return 3;
	}

private:
	bool isSquare(int n) {
		int sqrtN = sqrt(n);
		return pow(sqrtN, 2) == n;
	}
};
