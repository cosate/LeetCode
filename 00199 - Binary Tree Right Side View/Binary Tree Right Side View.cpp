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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> que;
        queue<TreeNode*> temp;
        que.push(root);
        while(!que.empty())
        {
            while(!que.empty())
            {
                temp.push(que.front());
                que.pop();
            }
            res.push_back(temp.back()->val);
            while(!temp.empty())
            {
                if(temp.front()->left != NULL)
                    que.push(temp.front()->left);
                if(temp.front()->right != NULL)
                    que.push(temp.front()->right);
                temp.pop();
            }
        }
        return res;
    }
};