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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        if(root == NULL)
            return res;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            if(temp->left == NULL && temp->right == NULL)
            {
                res.push_back(temp->val);
                s.pop();
                while(!s.empty() && (s.top()->left == temp || s.top()->right == temp))
                {
                    temp = s.top();
                    res.push_back(temp->val);
                    s.pop();
                }
            }
            else
            {
                TreeNode* l = temp->left;
                TreeNode* r = temp->right;
                if(r != NULL)
                    s.push(r);
                if(l != NULL)
                    s.push(l);
            }
        }
        return res;
    }
};