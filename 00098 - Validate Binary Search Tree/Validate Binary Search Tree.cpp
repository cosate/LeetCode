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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return true;
        }
        else
        {
            if(root->left == NULL && root->right != NULL)
                return minofBST(root->right) > root->val && isValidBST(root->right);
            else if(root->left != NULL && root->right == NULL)
                return maxofBST(root->left) < root->val && isValidBST(root->left);
            else
                return maxofBST(root->left)<root->val && minofBST(root->right)>root->val && isValidBST(root->left) && isValidBST(root->right);
        } 
    }
    int maxofBST(TreeNode* root)
    {
        if(root->right == NULL)
            return root->val;
        else
        {
            return maxofBST(root->right);
        }
    }
    int minofBST(TreeNode* root)
    {
        if(root->left == NULL)
            return root->val;
        else
        {
            return minofBST(root->left);
        }
    }
};