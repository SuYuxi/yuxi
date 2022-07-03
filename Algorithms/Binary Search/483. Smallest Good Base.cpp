class Solution {
#define ll long long
public:
    string smallestGoodBase(string n) {
        ll num = stoll(n);

        for(int m = log(num) / log(2) + 1; m > 1; --m) {
            ll lo = 2, hi = num - 1;
            while(lo <= hi) {
                ll mid = lo + (hi - lo) / 2;
                ll val = 1, sum = 1, p = 1;
                bool flag = false;
                while(p < m) {
                    if(val > (num - sum) / mid) {
                        flag = true;
                        break;
                    }
                    val *= mid;
                    sum += val;
                    ++p;
                }
                if(flag || sum > num) {
                    hi = mid - 1;
                }
                else if(sum < num) {
                    lo = mid + 1;
                }
                else {
                    return to_string(mid);
                }
            }
            
        }
        return to_string(num - 1);
    }
};
