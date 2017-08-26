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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0)
            return NULL;
        else
            return construct(preorder,0,n-1,inorder,0,n-1);
    }
    TreeNode* construct(vector<int>& pre, int prestart, int preend, vector<int>& in, int instart, int inend)
    {
        TreeNode* result = new TreeNode(pre[prestart]);
        if(preend < prestart)
            return NULL;
        else if(preend - prestart == 0)
            return result;
        int i = instart;
        for(; i <= inend; i++)
        {
            if(in[i] == pre[prestart])
                break;
        }
        int leftlen = i-instart;
        result->left = construct(pre, prestart+1,prestart+leftlen,in,instart,instart+leftlen);
        result->right = construct(pre,prestart+leftlen+1,preend,in,instart+leftlen+1,inend);
        return result;
    }
};