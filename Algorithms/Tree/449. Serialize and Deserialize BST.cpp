/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string code;
        preorder(root, code);
        return code;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;      
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }

private:
    void preorder(TreeNode* node, string& code) {
        if(node == nullptr) return;
        char buf[4];
        memcpy(buf, &(node->val), sizeof(int));
        for(int i = 0; i < 4; ++i) {
            code.push_back(buf[i]);
        }
        preorder(node->left, code);
        preorder(node->right, code);
    }
    TreeNode* reconstruct(string& data, int& pos, int minVal, int maxVal) {
        if(pos >= data.size()) return nullptr;
        int val;
        memcpy(&val, &data[pos], sizeof(int));
        if(val < minVal || val > maxVal) return nullptr;
        TreeNode* node = new TreeNode(val);
        pos += sizeof(int);
        node->left = reconstruct(data, pos, minVal, val);
        node->right = reconstruct(data, pos, val, maxVal);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
