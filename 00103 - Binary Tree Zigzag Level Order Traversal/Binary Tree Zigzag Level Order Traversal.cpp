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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        bool flag = true;
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
            if(flag == true)
            {
                flag = false;
            }
            else
            {
                flag = true;
                for(int i = 0; i<n/2; i++)
                {
                    int a = vec[n-1-i];
                    vec[n-1-i] = vec[i];
                    vec[i] = a;
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};