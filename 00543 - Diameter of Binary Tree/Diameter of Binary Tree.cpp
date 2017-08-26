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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = depth(root);
        if(d == 0)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        int dialeft = diameterOfBinaryTree(root->left);
        int diaright = diameterOfBinaryTree(root->right);
        return max(l+r, dialeft, diaright);
    }
    int depth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            int left = depth(root->left);
            int right = depth(root->right);
            return left>right ? left+1 : right+1;
        }
    }
    int max(int a, int b, int c)
    {
        int res = a;
        if(b>res)
            res = b;
        if(c>res)
        {
            res = c;
        }
        return res;
    }
};