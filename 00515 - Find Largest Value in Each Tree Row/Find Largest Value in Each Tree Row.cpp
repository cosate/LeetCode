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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> temp;
        vector<TreeNode*> level;
        while(!que.empty())
        {
            while(!que.empty())
            {
                level.push_back(que.front());
                que.pop();
            }
            for(int i = 0; i<level.size(); i++)
            {
                if(level[i]->left != NULL)
                    que.push(level[i]->left);
                if(level[i]->right != NULL)
                    que.push(level[i]->right);
                temp.push_back(level[i]->val);
            }
            result.push_back(max(temp));
            temp.clear();
            level.clear();
        }
        return result;
    }
    int max(vector<int> vec)
    {
        int len = vec.size();
        int res = vec[0];
        for(int i = 0; i<len; i++)
        {
            if(vec[i]>res)
                res = vec[i];
        }
        return res;
    }
};