/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root != NULL)
        {
            TreeLinkNode* templeft = root->left;
            TreeLinkNode* tempright = root->right;
            int begin = 1;
            while(right(templeft, begin) != NULL && left(tempright, begin) != NULL)
            {
                right(templeft, begin)->next = left(tempright, begin);
                begin++;
            }
            connect(root->left);
            connect(root->right);
        }
    }
    
    TreeLinkNode* right(TreeLinkNode* root, int level)
    {
        int h = height(root);
        if(level > h)
            return NULL;
        else
        {
            if(level == 1)
                return root;
            else
            {
                if(height(root->right) >= level-1)
                    return right(root->right, level-1);
                else
                    return right(root->left, level-1);
            }
        }
    }
    
    TreeLinkNode* left(TreeLinkNode* root, int level)
    {
        int h = height(root);
        if(level > h)
            return NULL;
        else
        {
            if(level == 1)
                return root;
            else
            {
                if(height(root->left) >= level-1)
                    return left(root->left, level-1);
                else
                    return left(root->right, level-1);
            }
        }
    }
    
    int height(TreeLinkNode* root)
    {
        if(root == NULL)
            return 0;
        else
        {
            return max(height(root->left), height(root->right)) + 1;
        }
    }
};