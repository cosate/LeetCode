/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        else if(root->left == NULL && root->right == NULL)
            return true;
        else
        {
            int hl = height(root->left);
            int hr = height(root->right);
            return isBalanced(root->left) && isBalanced(root->right) && (hl - hr)<2 && (hl - hr)>-2;
        }
    }
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right ==NULL)
            return 1;
        else
        {
            int m = height(root->left);
            int n = height(root->right);
            return m>n ? m+1: n+1;
        }
    }
};