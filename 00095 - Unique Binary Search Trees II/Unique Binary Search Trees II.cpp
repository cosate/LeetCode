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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> alltrees(n+1);
        if(n == 0)
            return alltrees[0];
        alltrees[0].resize(0);
        TreeNode* t1 = new TreeNode(1);
        alltrees[1].push_back(t1);
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(j == 1)
                {
                    for(int l = 0; l < alltrees[i-j].size(); l++)
                    {
                        TreeNode* root = new TreeNode(j);
                        root->left = NULL;
                        root->right = createnewtreewithoffset(alltrees[i-j][l], j);
                        alltrees[i].push_back(root);
                    }
                }
                else if(j == i)
                {
                    for(int k = 0; k < alltrees[j-1].size(); k++)
                    {
                        TreeNode* root = new TreeNode(j);
                        root->left = createnewtreewithoffset(alltrees[j-1][k], 0);
                        root->right = NULL;
                        alltrees[i].push_back(root);
                    }
                }
                else
                {
                    for(int k = 0; k < alltrees[j-1].size(); k++)
                    {
                        for(int l = 0; l < alltrees[i-j].size(); l++)
                        {
                            TreeNode* root = new TreeNode(j);
                            root->left = createnewtreewithoffset(alltrees[j-1][k], 0);
                            root->right = createnewtreewithoffset(alltrees[i-j][l], j);
                            alltrees[i].push_back(root);
                        }
                    }
                }
            }
        }
        return alltrees[n];   
    }
    
    TreeNode* createnewtreewithoffset(TreeNode* root, int offset)
    {
        TreeNode* res;
        if(root == NULL)
            return NULL;
        res = new TreeNode(root->val + offset);
        res->left = createnewtreewithoffset(root->left, offset);
        res->right = createnewtreewithoffset(root->right, offset);
        return res;
    }
};