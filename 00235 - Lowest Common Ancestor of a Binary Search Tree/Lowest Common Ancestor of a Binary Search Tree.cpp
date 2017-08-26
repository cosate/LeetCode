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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        if(p->val > q->val)
        {
            TreeNode* temp = p;
            p = q;
            q = temp;
        }
        if(p->val <= root->val && q->val >= root->val)
        {
            return root;
        }
        else if(p->val > root->val && q->val >= root->val)
        {
            if(q->val > root->val)
                return lowestCommonAncestor(root->right,p,q);
            else
                return root;
        }
        else if(p->val <= root->val && q->val < root->val)
        {
            if(p->val < root->val)
                return lowestCommonAncestor(root->left,p,q);
            else
                return root;
        }
    }
};