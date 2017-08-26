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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* r = q->next;
        p->next = NULL;
        while(r != NULL)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        return q;
    }
};