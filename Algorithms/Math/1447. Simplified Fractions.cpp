class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> fractions;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(std::gcd(i, j) == 1)
                {
                    fractions.emplace_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return fractions;
    }
};
