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
    int countNodes(TreeNode* root) {
        int h = height(root);
        int res = power(2, h) - 1;
        count(root, res, h);
        return res;
    }
    int height(TreeNode* root)
    {
        int h = 0;
        TreeNode* tmp = root;
        while(tmp != NULL)
        {
            tmp = tmp->left;
            h++;
        }
        return h;
    }
    
    void count(TreeNode* root, int& sum, int hei)
    {
        --hei;
        if(hei>0)
        {
            if(height(root->right) < height(root->left))
            {
                sum -= (power(2, hei-1));
                count(root->left, sum, hei);
            }
            else
            {
                count(root->right, sum, hei);
            }
        }
    }
    int power(int x, int y)
    {
        int res = 1;
        for(int i = 0; i < y; i++)
        {
            res = res*x;
        }
        return res;
    }
};