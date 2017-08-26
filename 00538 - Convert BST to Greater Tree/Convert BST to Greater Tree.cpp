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
    TreeNode* convertBST(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(root,vec);
        int len = vec.size();
        for(int i = len-2; i >= 0; i--)
        {
            vec[i]->val += vec[i+1]->val;
        }
        return root;
    }
    
    void inorder(TreeNode* root,vector<TreeNode*>& vec)
    {
        if(root==NULL)
        {}
        else
        {
            TreeNode* p = root;
            inorder(root->left,vec);
            vec.push_back(p);
            inorder(root->right,vec);
        }
    }
};