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
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        inorder(vec,root);
        int len = vec.size();
        int res = INT_MAX;
        for(int i = 0; i<len-1; i++)
        {
            if((vec[i+1]-vec[i]) < res)
                res = vec[i+1]-vec[i];
        }
        return res;
    }
    void inorder(vector<int>& vec, TreeNode* root)
    {
        if(root == NULL)
        {}
        else if(root->left == NULL && root->right == NULL)
        {
            vec.push_back(root->val);
        }
        else
        {
            inorder(vec,root->left);
            vec.push_back(root->val);
            inorder(vec,root->right);
        }
    }
};