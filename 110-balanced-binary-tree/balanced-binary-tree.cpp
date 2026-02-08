class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root) return 0;

        int leftmax = height(root->left);
        int rightmax = height(root->right);

        return max(leftmax, rightmax) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;

        int leftheight = height(root->left);
        int rightheight = height(root->right);

        bool rootAns = (abs(leftheight - rightheight) <= 1);
        
        bool rootLeftAns = isBalanced(root->left);
        bool rootRightAns = isBalanced(root->right);

        // for balanced tree root, rootChildren all should balanced

        if(rootAns && rootRightAns && rootLeftAns) return 1;

        return 0;
    }
};