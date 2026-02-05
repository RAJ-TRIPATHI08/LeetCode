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
    int maxSum;

    int solve(TreeNode* root)
    {
        if(!root)
            return 0;     // if no root exist there is no path

        int l = solve(root->left);
        int r = solve(root->right);

        // We have total 3 cases here
        // if all things are good means left and right both +ve
        int allGood = root->val + l + r;     // (1)

        // if any of them is -ve;

        int oneOfthemNeg = root->val + max(l, r);     // (2)

        // if there is only root val is +ve

        int onlyRootPos = root->val;    // (3)

        // we have to update maxSum from max of all 3

        maxSum = max({maxSum, allGood, oneOfthemNeg, onlyRootPos});

        // we have to return a valid sum to maintain valid path bcz 
        // we cant take a path of root and its left or right subtree 
        // we can onlly take the path which is only have a single direction
        return max(oneOfthemNeg, onlyRootPos);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = -1e9;
        solve(root);

        return maxSum;
    }
};