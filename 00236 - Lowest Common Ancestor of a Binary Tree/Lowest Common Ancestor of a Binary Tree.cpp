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
            return NULL;
        int pnode = find(root, p);
        int qnode = find(root, q);
        if(( pnode == 1 && qnode == 2) || (pnode == 2 && qnode == 1)) 
            return root;
        else if(pnode == 0 || qnode == 0)
            return root;
        else if(pnode == 1 && qnode == 1)
            return lowestCommonAncestor(root->left, p, q);
        else if(pnode == 2 && qnode == 2)
            return lowestCommonAncestor(root->right, p, q);
        else
            return NULL;
    }
    
    int find(TreeNode* root, TreeNode* target)
    {
        if(root == NULL)
            return -1;
        if(root == target)
            return 0;
        if(find(root->left, target) != -1)
            return 1;
        if(find(root->right, target) != -1)
            return 2;
        return -1;
    }
};