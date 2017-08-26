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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0)
            return NULL;
        else
            return construct(inorder,0,n-1,postorder,0,n-1);
    }
    TreeNode* construct(vector<int>& in, int instart, int inend, vector<int>& post, int poststart, int postend)
    {
        TreeNode* result = new TreeNode(post[postend]);
        if(postend < poststart)
            return NULL;
        else if(postend == poststart)
            return result;
        int i = instart;
        for(; i <= inend; i++)
        {
            if(in[i] == post[postend])
                break;
        }
        int leftlen = i-instart;
        result->left = construct(in, instart, instart+leftlen-1, post, poststart, poststart+leftlen-1);
        result->right = construct(in,instart+leftlen+1,inend,post,poststart+leftlen,postend-1);
        return result;
    }
};