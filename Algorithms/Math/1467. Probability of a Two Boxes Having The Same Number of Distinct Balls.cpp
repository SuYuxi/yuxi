//original
class Solution {
public:
    double getProbability(vector<int>& balls) {
        colors = balls.size();
        size = std::accumulate(balls.begin(), balls.end(), 0);
        vector<int> aSet(colors, 0), bSet(colors, 0);
        return dfs(balls, aSet, bSet, 0, 0, 0) / permutation(balls);
    }

private:
    double dfs(vector<int>& balls, vector<int>& aSet, vector<int>& bSet, int inx, int aSize, int bSize) {
        if(aSize > size / 2 || bSize > size / 2) return 0;
        if(inx == colors)
        {
            int aColor = 0, bColor = 0;
            for(int i = 0; i < colors; ++i)
            {
                aColor += aSet[i] > 0;
                bColor += bSet[i] > 0;
            }
            if(aColor != bColor) return 0;
            return permutation(aSet) * permutation(bSet);
            
        }
        double ans = 0;
        for(int i = 0; i <= balls[inx]; ++i)
        {
            aSet[inx] = i;
            bSet[inx] = balls[inx] - i;
            ans += dfs(balls, aSet, bSet, inx + 1, aSize + aSet[inx], bSize + bSet[inx]);
        }
        return ans;
    }
    double permutation(vector<int>& balls) {
        double ans = 1;
        for(int i = 0, j = 1; i < balls.size(); ++i)
        {
            for(int k = 1; k <= balls[i]; ++k, ++j)
            {
                ans = ans * j / k;
            }
        }
        return ans;
    }
    int size, colors;
};

//optimized
class Solution {
public:
    static constexpr int fact[7] = {1, 1, 2, 6, 24, 120, 720};
    
    double getProbability(vector<int>& balls) {
        colors = balls.size();
        size = std::accumulate(balls.begin(), balls.end(), 0);
        vector<int> aSet(colors, 0), bSet(colors, 0);
        halfFactorial = factorial(size / 2);
        return dfs(balls, aSet, bSet, 0, 0, 0) / permutation(balls);
    }

private:
    double dfs(vector<int>& balls, vector<int>& aSet, vector<int>& bSet, int inx, int aSize, int bSize) {
        if(aSize > size / 2 || bSize > size / 2) return 0;
        if(inx == colors)
        {
            int aColor = 0, bColor = 0;
            for(int i = 0; i < colors; ++i)
            {
                aColor += aSet[i] > 0;
                bColor += bSet[i] > 0;
            }
            if(aColor != bColor) return 0;
            return pow(halfFactorial, 2) / (sumFactorial(aSet) * sumFactorial(bSet));
            
        }
        double ans = 0;
        for(int i = 0; i <= balls[inx]; ++i)
        {
            aSet[inx] = i;
            bSet[inx] = balls[inx] - i;
            ans += dfs(balls, aSet, bSet, inx + 1, aSize + aSet[inx], bSize + bSet[inx]);
        }
        return ans;
    }
    double factorial(int num) {
        double ans = 1;
        for(int i = 2; i <= num; ++i)
        {
            ans *= i;
        }
        return ans;
    }
    double sumFactorial(vector<int>& vec) {
        double ans = 1;
        for(int& num : vec)
        {
            ans *= fact[num];
        }
        return ans;
    }
    double permutation(vector<int>& vec) {
        double ans = 1;
        for(int i = 0, j = 1; i < vec.size(); ++i)
        {
            for(int k = 1; k <= vec[i]; ++k, ++j)
            {
                ans = ans * j / k;
            }
        }
        return ans;
    }
    int size, colors;
    double halfFactorial;
};
