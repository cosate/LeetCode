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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode* p = root;
        vector<int> result;
        if(root == NULL)
            return result;
        else
        {
            while(!s.empty() || p != NULL)
            {
                while(p!= NULL)
                {
                    s.push(p);
                    p = p->left;
                }
                if(!s.empty())
                {
                    p = s.top();
                    result.push_back(p->val);
                    s.pop();
                    p = p->right;
                }
            }
        }
        return result;
    }
};