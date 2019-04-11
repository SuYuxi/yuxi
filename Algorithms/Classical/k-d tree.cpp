//kd-tree Implemention
//https://leileiluoluo.com/posts/kdtree-algorithm-and-implementation.html
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

typedef vector<int> Point; //Presents Point type by vector<int> like (x, y, z)

struct kdTreeNode {
	kdTreeNode(Point _val = Point(), shared_ptr<kdTreeNode> _leftNode = nullptr, shared_ptr<kdTreeNode> _rightNode = nullptr)
			  : val(_val)
			  , leftNode(_leftNode)
			  , rightNode(_rightNode)
			  {}
	Point val;
	shared_ptr<kdTreeNode> leftNode;
	shared_ptr<kdTreeNode> rightNode;
};

//leftNode store points that point[splitDim] < node[splitDim]
//rightNode store points that point[splitDim] >= node[splitDim]
class kdTree {
public:
	kdTree() : dimension(0), root(nullptr) {
	}

	shared_ptr<kdTreeNode> getKdTreeRoot() {
		return root;
	}

	bool buildKdTree(vector<Point>& points) { //All the points must be of same dimension like (x, y ,z) or (x, y) or what ever you like 
		if(points.empty() | points[0].empty()) return false;
		dimension = points[0].size();
		root = buildHelper(points, 0, 0, points.size() - 1);
		return root != nullptr ? true : false; //return false if cannot build kd Tree by input points;
	}

	//print all Kd Tree's nodes layer by layer using breadth first search
	void printKdTree() { 
		queue<shared_ptr<kdTreeNode>> q;
		q.emplace(root);
		shared_ptr<kdTreeNode> node;
		cout << "Points are:" << endl;;
		while(!q.empty())
		{
			node = q.front();
			q.pop();
			if(node != nullptr)
			{
				cout << "(";
				for_each(node->val.begin(), node->val.end() - 1, [](int& num) { cout << num << ", ";});
				cout << *(node->val.end() - 1) << ")" << endl;
				q.emplace(node->leftNode);
				q.emplace(node->rightNode);
			}
			else
			{
				cout << "(nullptr)" << endl;;
			}
		}
		cout << "End." << endl;;
	}

	shared_ptr<kdTreeNode> findMin(shared_ptr<kdTreeNode> node, int dim, int depth) //find the node with the minimum value on dim dimension
	{
		if(root == nullptr) return nullptr;
		shared_ptr<kdTreeNode> minimum = node;
		findMinHelper(minimum, node, dim, depth);
		return minimum;
	}

	bool addNode(Point point) {
		if(root == nullptr || point.size() != dimension) return false;
		shared_ptr<kdTreeNode> node = root;
		int depth = 0;
		int curDim;
		while(true)
		{
			curDim = depth % dimension;
			if(point[curDim] < node->val[curDim])
			{
				if(node->leftNode == nullptr)
				{
					node->leftNode = make_shared<kdTreeNode>(point);
					return true;
				}
				node = node->leftNode;
			}
			else
			{
				if(node->rightNode == nullptr)
				{
					node->rightNode = make_shared<kdTreeNode>(point);
					return true;
				}
				node = node->rightNode;
			}
			depth += 1;
		}
		
		return false;
	}

	void deleteNode(Point point) {
		if(point.size() != dimension) return;
		if(deleteNodeHelper(root, point, 0)) { root = nullptr; }
	}

	bool deleteNodeHelper(shared_ptr<kdTreeNode>& node, Point& point, int depth) { //return true means the child node should be deleted
		if(node == nullptr) return false;
		int curDim = depth % dimension;
		if(point == node->val)
		{
			if(node->rightNode != nullptr)
			{
				shared_ptr<kdTreeNode> minimumNode = findMin(node->rightNode, curDim, depth + 1);
				node->val = minimumNode->val; // do not swap(node->val, minimumNode) which would break the structure of kd-tree and result in not finding the node to delete 
				if(deleteNodeHelper(node->rightNode, minimumNode->val, depth + 1)) { node->rightNode = nullptr; }
			}
			else if(node->leftNode != nullptr)
			{
				shared_ptr<kdTreeNode> minimumNode = findMin(node->leftNode, curDim, depth + 1);
				node->val = minimumNode->val;
				if(deleteNodeHelper(node->leftNode, minimumNode->val, depth + 1)) { node->leftNode = nullptr; }
				node->rightNode = node->leftNode;
				node->leftNode = nullptr;
			}
			else
			{
				return true; //return true to inform outter deleteNodeHelper to release this pointer;
			}
		}
		else
		{
			if(point[curDim] < node->val[curDim])
			{
				if(deleteNodeHelper(node->leftNode, point, depth + 1)) { node->leftNode = nullptr; }
			}
			else
			{
				if(deleteNodeHelper(node->rightNode, point, depth + 1)) { node->rightNode = nullptr; }
			}
		}
		return false;
	}

	shared_ptr<kdTreeNode> findNearestNode() {
		return nullptr;
	}


private:
	shared_ptr<kdTreeNode> buildHelper(vector<Point>& points, int depth, int leftBorder, int rightBorder) { //recursively create kd Tree
		if(leftBorder > rightBorder) return nullptr;
		int curDim = depth % dimension;
		sort(points.begin() + leftBorder, points.begin() + rightBorder + 1, [curDim](Point& a, Point& b) { return a[curDim] < b[curDim]; });
		int midInx = leftBorder + (rightBorder - leftBorder) / 2;
		while(midInx > leftBorder && points[midInx - 1][curDim] == points[midInx][curDim]) // keep all the points that point[splitDim] >= midInx[splitDim] on the right of midInx
		{
			midInx -= 1;
		}
		shared_ptr<kdTreeNode> node = make_shared<kdTreeNode>(points[midInx]);
		node->leftNode = buildHelper(points, depth + 1, leftBorder, midInx - 1);
		node->rightNode = buildHelper(points, depth + 1, midInx + 1, rightBorder);
		return node;
	}

	void findMinHelper(shared_ptr<kdTreeNode>& minimum, shared_ptr<kdTreeNode>& node, int dim, int depth)
	{
		if(node == nullptr) return;
		if(node->val[dim] < minimum->val[dim]) { minimum = node; }
		findMinHelper(minimum, node->leftNode, dim, depth + 1);
		if(depth % dimension != dim) { findMinHelper(minimum, node->rightNode, dim, depth + 1); }
	}
	
	int dimension;
	shared_ptr<kdTreeNode> root;

};

int main() {
	vector<Point> points = {{1,2,30}, {2,3,14}, {3,4,66}, {4,5,26}, {1,12,33}, {1,52,73}};
	kdTree kd;
	if(kd.buildKdTree(points))
	{
		kd.addNode({100,-100,32});
		kd.printKdTree();
		kd.deleteNode({1, 52, 73});
		kd.deleteNode({100, -100, 32});
		kd.printKdTree();
		return 1;
	}
	else
	{
		cout << "something wrong" << endl;
		return -1;
	}
	
	return 0;
}
