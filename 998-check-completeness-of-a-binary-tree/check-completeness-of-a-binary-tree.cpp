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
class Solution {
public:
    int cnt = 0;
    int count(TreeNode* root)
    {
        if(!root) return 0;
        
        return 1 + count(root->left) + count(root->right);
    }

    bool isCBT(TreeNode* root, int i)
    {
        if(!root) return true;
        
        if(i > cnt)  return false;
        return isCBT(root->left, 2*i) && isCBT(root->right, 2*i+1);
    }

    bool isCompleteTree(TreeNode* root) {
        cnt = count(root);
        
        return isCBT(root, 1);
    }
};