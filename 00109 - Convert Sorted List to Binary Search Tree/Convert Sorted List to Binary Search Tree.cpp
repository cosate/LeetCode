/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        vector<int> vec;
        while(p != NULL)
        {
            vec.push_back(p->val);
            p = p->next;
        }
        return sortedArrayToBST(vec);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n = nums.size();
        TreeNode* root = construct(nums,0,n-1);
        return root;
    }
    TreeNode* construct(vector<int>& nums, int begin, int end)
    {
        if(begin > end)
            return NULL;
        TreeNode* node = new TreeNode(nums[(begin+end)/2]);
        if(begin != end)
        {
            node->left = construct(nums,begin,(begin+end)/2-1);
            node->right = construct(nums,(begin+end)/2+1,end);
        }
        return node;
    }
};