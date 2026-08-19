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
    using ll = unsigned long long;
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> tree;

        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll res = 0;

        while(!q.empty())
        {
            int n = q.size();

            ll j = q.back().second;
            ll i = q.front().second;
            res = max(res, j-i+1);

            for(int i = 0; i < n; i++)
            {
                auto [curr, idx] = q.front();
                q.pop();

                if(curr->left)
                    q.push({curr->left, 2*idx+1});

                if(curr->right)
                    q.push({curr->right, 2*idx+2});
            }
        }

        return (int)res;
    }
};