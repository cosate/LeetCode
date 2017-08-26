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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        kth(root, k, vec);
        return vec[k-1];
    }
    
    void kth(TreeNode* root, int k, vector<int>& vec)
    {
        if(root != NULL)
        {
            kth(root->left, k, vec);
            vec.push_back(root->val);
            kth(root->right, k, vec);
        }
    }
};