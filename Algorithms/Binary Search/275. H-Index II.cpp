class Solution {
    
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int size = citations.size();
        int left = 0, right = size - 1;
        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if(citations[mid] >= size - mid)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return min(citations[left], size - left);
    }
};
