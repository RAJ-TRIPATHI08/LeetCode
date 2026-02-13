/**
 * Definition for a binary tree TreeNode.
 * struct TreeTreeNode {
 *     int val;
 *     TreeTreeNode *left;
 *     TreeTreeNode *right;
 *     TreeTreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeTreeNode(int x, TreeTreeNode *left, TreeTreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    class Node {
    public:
        bool isBST;
        int sum;
        int mn;
        int mx;

        Node(bool b, int s, int mi, int ma) {
            isBST = b;
            sum = s;
            mn = mi;
            mx = ma;
        }
    };

    Node dfs(TreeNode* root) {
        if (!root) {
            return Node(true, 0, INT_MAX, INT_MIN);
        }

        Node left = dfs(root->left);
        Node right = dfs(root->right);

        if (left.isBST && right.isBST && left.mx < root->val && root->val < right.mn) {
            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            int mn = min(root->val, left.mn);
            int mx = max(root->val, right.mx);

            return Node(true, sum, mn, mx);
        }

        return Node(false, 0, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};