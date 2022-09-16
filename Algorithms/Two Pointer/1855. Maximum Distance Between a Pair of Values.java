class Solution {
    public int maxDistance(int[] A, int[] B) {
        int res = 0, i = 0, n = A.length, m = B.length;
        for (int j = 0; j < m; ++j) {
            while (i < n && A[i] > B[j])
                i++;
            if (i == n) break;
            res = Math.max(res, j - i);
        }
        return res;
    }
}
