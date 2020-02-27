#include <vector>

class DSU {

public:
    DSU(int size) {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        parent[find(x)] = find(y);
    }

    std::vector<int> parent;
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        DSU dsu(4 * N * N);
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                int index = 4 * (r * N + c);
                if (grid[r][c] != '\\')
                {
                    dsu.Union(index + 0, index + 3);
                    dsu.Union(index + 1, index + 2);
                }

                if (grid[r][c] != '/')
                {
                    dsu.Union(index + 0, index + 1);
                    dsu.Union(index + 2, index + 3);
                }

                if (r > 0)
                {
                    dsu.Union(index + 0, (index - 4 * N) + 2);
                }

                if (r < N - 1)
                {
                    dsu.Union(index + 2, (index + 4 * N) + 0);
                }

                if (c > 0)
                {
                    dsu.Union(index + 3, (index - 4) + 1);
                }

                if (c < N - 1)
                {
                    dsu.Union(index + 1, (index + 4) + 3);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 4 * N * N; ++i)
        {
            if (dsu.find(i) == i)
            {
                ++ans;
            }
        }
        return ans;
    }
};