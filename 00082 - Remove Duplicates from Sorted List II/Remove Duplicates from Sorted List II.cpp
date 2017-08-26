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
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* pre = new ListNode(INT_MAX);
        pre->next = head;
        ListNode* beforep = pre;
        ListNode* p = head;
        ListNode* q = p->next;
        while(q != NULL)
        {
            while( q != NULL && p->val == q->val)
            {
                q = q->next;
            }
            if(p->next != q)
                beforep->next = q;
            else
                beforep = beforep->next;
            p = q;
            if(q != NULL)
                q = q->next;
        }
        return pre->next;
    }
};