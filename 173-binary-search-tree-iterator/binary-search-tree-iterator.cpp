/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inorder;
    BSTIterator(TreeNode* root) {
        dfs(root);
    }

    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    
    int idx = 0;
    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        return !(idx == inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */