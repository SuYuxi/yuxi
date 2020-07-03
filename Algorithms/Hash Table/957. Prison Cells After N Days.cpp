class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> first, next(cells.size(), 0);
        for(int cycle = 0; N-- > 0; ++cycle)
        {
            for(int j = 1; j < cells.size() - 1; ++j) next[j] = (cells[j - 1] == cells[j + 1]);
            if(cycle == 0) first = next;
            else if(first == next)
            {
                N %= cycle;
            }
            cells = next;
        }
        return cells;
    }
};
