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
    vector<int> arr;
    void inOrder(TreeNode* root)
    {
        if(!root) return;

        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }
    
    TreeNode* AVLTree(int s, int e)
    {
        if(s > e) return NULL;

        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = AVLTree(s, mid - 1);
        root->right = AVLTree(mid + 1, e);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return AVLTree(0, arr.size()-1);
    }
};