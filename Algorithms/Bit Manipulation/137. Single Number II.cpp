/////  num   one   two
/////   1     0     0
/////   1     1     0
/////   1     0     1
/////   1     0     0
/////   1     1     0
/////   1     0     1

/////  num   one   two
/////   0     0     0
/////   0     0     0

/////  num   one   two
/////   0     1     0
/////   0     1     0

/////  num   one   two
/////   0     0     1
/////   0     0     1

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int& num : nums)
        {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};
