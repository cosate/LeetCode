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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        while(p != NULL && p->val == val)
        {
            p = p->next;
        }
        ListNode* q = p;
        if(p == NULL)
            return q;
        ListNode* r = p->next;
        while(r != NULL)
        {
            if(r->val == val)
            {
                p->next = r->next;
                r = r->next;
            }
            else
            {
                p = p->next;
                r = r->next;
            }
        }
        return q;
    }
};