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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        else if(root->left == NULL && root->right == NULL)
        {
            string s = "";
            s += to_string(root->val);
            res.push_back(s);
            return res;
        }
        else
        {
            vector<string> left = binaryTreePaths(root->left);
            vector<string> right = binaryTreePaths(root->right);
            res.insert(res.end(),left.begin(),left.end());
            res.insert(res.end(),right.begin(),right.end());
            for(auto i = res.begin(); i != res.end(); i++)
            {
                string temp = to_string(root->val);
                *i =  temp + "->" + *i;
            }
            return res;
        }
    }
};