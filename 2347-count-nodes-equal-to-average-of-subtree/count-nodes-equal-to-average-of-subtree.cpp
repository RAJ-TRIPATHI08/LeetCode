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
    int res = 0;

    pair<int, int> dfs(TreeNode* root)
    {
        if(!root)
            return {0, 0};    // {sum of subtree, noOfNodes in subtree}

        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        int cnt = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;

        if(sum/ cnt == root->val)
            res++;

        return {cnt, sum};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};