class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> count(size + 1, 0);
        
        for(int& citation : citations)
        {
            if(citation >= size)
            {
                count[size] += 1;
            }
            else
            {
                count[citation] += 1;
            }
        }
        
        for(int i = size, sum = 0; i >= 0; --i)
        {
            sum += count[i];
            if(sum >= i)
            {
                return i;
            }
        }
        return -1;
    }
};
