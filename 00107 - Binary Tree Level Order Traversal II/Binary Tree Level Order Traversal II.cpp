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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        TreeNode* tn = root;
        q.push(tn);
        while(!q.empty())
        {
            vector<int> vec;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                if(q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                vec.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(vec);
        }
        int m = result.size();
        for(int i = 0; i<m/2;i++)
        {
            vector<int> vec = result[m-1-i];
            result[m-1-i] = result[i];
            result[i] = vec;
        }
        return result;
    }
};