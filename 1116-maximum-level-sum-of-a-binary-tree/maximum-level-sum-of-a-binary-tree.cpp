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
    using ll = long long;
    int maxLevelSum(TreeNode* root) {
        vector<ll> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            ll sum = 0;

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(sum);
        }

        int res = 1;

        int sum = ans[0];
        for(int i = 1; i < ans.size(); i++)
        {
            if(sum < ans[i])
            {
                sum = ans[i];
                res = i+1;
            }
        }
        return res;
    }
};