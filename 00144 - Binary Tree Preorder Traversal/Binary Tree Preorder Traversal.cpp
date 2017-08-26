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
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> sta;
        vector<int> res;
        
        if(root == NULL)
            return res;
        sta.push(root);
        
        while(!sta.empty())
        {
            res.push_back(sta.top()->val);
            TreeNode* temp = sta.top();
            sta.pop();
            if(temp->right != NULL)
                sta.push(temp->right);
            if(temp->left != NULL)
                sta.push(temp->left);
        }
        return res;
    }
};