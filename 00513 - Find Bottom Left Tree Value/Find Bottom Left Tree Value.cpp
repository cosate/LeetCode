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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right ==NULL)
            return root->val;
        else if(heightoftree(root->left) >= heightoftree(root->right))
            return findBottomLeftValue(root->left);
        else
            return findBottomLeftValue(root->right);
    }
    
    int heightoftree(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            int l = heightoftree(root->left);
            int r = heightoftree(root->right);
            return l>r ? l+1 : r+1; 
        }
    }
};