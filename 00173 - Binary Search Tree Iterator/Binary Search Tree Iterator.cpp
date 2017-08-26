/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> in;
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL)
        {
            in.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(in.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        int res = in.top()->val;
        TreeNode* t = in.top()->right;
        in.pop();
        while(t != NULL)
        {
            in.push(t);
            t = t->left;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */