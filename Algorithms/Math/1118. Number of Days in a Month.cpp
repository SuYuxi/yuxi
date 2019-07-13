class Solution {
public:
    int numberOfDays(int Y, int M) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(M != 2) return months[M - 1];
        if((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0)) return 29; 
        return 28;
    }
};
