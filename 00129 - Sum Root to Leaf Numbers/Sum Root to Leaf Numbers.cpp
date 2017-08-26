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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int num = 0;
        sumleaf(root, res, num);
        return res;
    }
    
    void sumleaf(TreeNode* root, int& result, int num)
    {
        if(root != NULL)
        {
            if(root->left == NULL && root->right == NULL)
            {
                result = result + num*10 + root->val;
            }
            else
            {
                sumleaf(root->left, result, num*10+root->val);
                sumleaf(root->right, result, num*10+root->val);
            }
        }
    }
};