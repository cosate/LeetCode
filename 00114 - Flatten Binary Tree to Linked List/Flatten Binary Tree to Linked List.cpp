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
    void flatten(TreeNode* root) {
        stack<TreeNode*> ss;
        if(root != NULL)
        {
            ss.push(root);
            while(!ss.empty())
            {
                TreeNode* temp = ss.top();
                ss.pop();
                if(temp->right != NULL)
                    ss.push(temp->right);
                if(temp->left != NULL)
                    ss.push(temp->left);
                temp->left = NULL;
                if(!ss.empty())
                {
                    temp->right = ss.top();
                }
            }
        }
    }
};