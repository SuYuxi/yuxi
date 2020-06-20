class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1);
        vector<int> numbers(n);
        factorial[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            numbers[i - 1] = i;
            factorial[i] = factorial[i - 1] * i; 
        }
        
        string res;
        k -= 1;
        for(int i = 1; i <= n; ++i)
        {
            int index = k / factorial[n - i];
            res.push_back('0' + numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[n - i];
        }        
        return res;     
    }
};
