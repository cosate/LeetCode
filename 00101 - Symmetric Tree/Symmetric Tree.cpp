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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else if(root->left == NULL && root->right == NULL) return true;
        else
        {
            return isMirror(root->left,root->right);
        }
    }
    bool isMirror(TreeNode *p, TreeNode * q)
    {
        if(p == NULL && q == NULL) return true;
        else if( p == NULL && q != NULL) return false;
        else if( p != NULL && q == NULL) return false;
        else
        {
            return ((p->val == q->val) && isMirror(p->left,q->right) && isMirror(p->right, q->left));
        }
    }
};