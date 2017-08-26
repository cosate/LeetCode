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
    vector<int> findMode(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
    
    int currentmax = 0;
    int currentvalue;
    int tempmax = 0;
    
    void inorder(TreeNode* root, vector<int>& vec)
    {
        if(root != NULL)
        {
            inorder(root->left, vec);
            tempmax++;
            if(root->val != currentvalue)
            {
                currentvalue = root->val;
                tempmax = 1;
            }
            if(tempmax > currentmax)
            {
                vec.clear();
                vec.push_back(root->val);
                currentmax = tempmax;
            }
            else if(tempmax == currentmax)
            {
                vec.push_back(root->val);
            }
            inorder(root->right, vec);
        }
    }
};