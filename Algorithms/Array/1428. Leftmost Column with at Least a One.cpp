/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int row = 0, col = size[1] - 1;
        while(row < size[0] && col >= 0)
        {
            int val = binaryMatrix.get(row, col);
            if(val == 0)
            {
                row += 1;
            }
            else
            {
                col -= 1;
            }
        }
        return (col == size[1] - 1) ? -1 : col + 1;
    }
};
