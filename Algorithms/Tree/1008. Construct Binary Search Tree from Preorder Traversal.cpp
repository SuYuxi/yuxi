/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//top-down best
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *cur = root;
        for(int i=1; i<preorder.size();i++){
            
            cur = root; 
            TreeNode* node = new TreeNode(preorder[i]);
            while(true){
                if(preorder[i] > cur->val){
                    
                    if(cur->right == NULL){
                        
                        cur->right = node;
                        break;
                    } else cur = cur->right;
                } else {
                    if(cur->left == NULL){
                        cur->left = node;
                        break;
                    } else cur = cur->left;
                }
            }
            
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		return dfs(preorder, 0, preorder.size() - 1);
    }
	TreeNode* dfs(vector<int>& preorder, int left, int right)
	{
		if(left > right) return nullptr;
		TreeNode* node = new TreeNode(preorder[left++]);
		int pivot = left;
		while(pivot <= right && preorder[pivot] < node->val)
		{
			pivot += 1;
		}
		node->left = dfs(preorder, left, pivot - 1);
		node->right= dfs(preorder, pivot, right);
		return node;
	}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
		inx = 0;
		return dfs(preorder, INT_MAX);
	}

    TreeNode* dfs(vector<int>& preorder, int bound)
	{
		if(inx >= preorder.size()) return nullptr;
		if(preorder[inx] > bound) return nullptr;
		TreeNode* node = new TreeNode(preorder[inx]);
		inx += 1;
		node->left = dfs(preorder, node->val); 
		node->right = dfs(preorder, bound); 
		return node;	
	}

private:
	int inx;
};


