class Solution {
public:
    bool solve(TreeNode* root, long min, long max) {
        if(!root) return 1;

        if(root->val > min && root->val < max) {
            bool left = solve(root->left, min, root->val);
            bool right = solve(root->right, root->val, max);
            return left && right;
        }

        return 0;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};