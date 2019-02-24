/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {

		return recursion(grid, 0, 0, grid.size());
	}

	Node* recursion(vector<vector<int>>& grid, int x, int y, int len)
	{
		Node * node = new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
		if(len <= 1)
		{
			return node;
		}
		bool preval = grid[x][y];
		for(int row = x; row < x + len; row += 1)
		{
			for(int col = y; col < y + len; col += 1)
			{
				if(preval != grid[row][col])
				{
					node->isLeaf = false;
					node->topLeft = recursion(grid, x, y, len / 2);
					node->topRight = recursion(grid, x, y + len / 2, len / 2);
					node->bottomLeft = recursion(grid, x + len / 2, y, len / 2);
					node->bottomRight = recursion(grid, x + len / 2, y + len / 2, len / 2);
					return node;
				}
			}
		}
		return node;
	}
};
