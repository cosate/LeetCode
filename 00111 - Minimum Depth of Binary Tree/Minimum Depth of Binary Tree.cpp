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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root-> right ==NULL)
            return 1;
        else
        {
            int dl = minDepth(root->left);
            int dr = minDepth(root->right);
            if(dl == 0 ||dr ==0)
                return dl+dr+1;
            return ( dl<dr ) ? (dl+1) : (dr+1);
        }
    }
};