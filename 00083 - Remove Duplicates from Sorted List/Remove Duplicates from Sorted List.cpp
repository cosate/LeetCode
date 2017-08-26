/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * p = head;
        if(p == NULL)
            return NULL;
        ListNode * current = head;
        p = p->next;
        while(p != NULL)
        {
            if(p->val == current->val)
            {
                current->next = p->next;
                p = p->next;
            }
            else
            {
                current = p;
                p = p->next;
            }
        }
        return head;
    }
};