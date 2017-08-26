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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        find(root, sum, res, temp);
        return res;
    }
    
    void find(TreeNode* root, int sum, vector<vector<int>>& result, vector<int> vec)
    {
        if(root != NULL)
        {
            vec.push_back(root->val);
            if(root->left == NULL && root->right == NULL)
            {
                if(root->val == sum)
                {
                    result.push_back(vec);
                }
            }
            else
            {
                find(root->left, sum-root->val, result, vec);
                find(root->right, sum-root->val, result, vec);
            }
        }
    }
};