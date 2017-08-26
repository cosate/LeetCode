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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        ListNode* ret = new ListNode(INT_MIN);
        ListNode* p = head;
        while(p != NULL)
        {
            ListNode* firstbig = ret;
            ListNode* lastsmall = NULL;
            while(firstbig != NULL && p->val >= firstbig->val)
            {
                lastsmall = firstbig;
                firstbig = firstbig->next;
            }
            ListNode* q = p;
            p = p->next;
            lastsmall->next = q;
            q->next = firstbig;
        }
        return ret->next;
    }
};