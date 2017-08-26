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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        else if(head->next == NULL)
            return head;
        else
        {
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* oddtail = odd;
            ListNode* eventail = even;
            ListNode*p = even->next;
            bool isodd = true;
            while(p != NULL)
            {
                if(isodd)
                {
                    oddtail->next = p;
                    oddtail = oddtail->next;
                    isodd = false;
                }
                else
                {
                    eventail->next = p;
                    eventail = eventail->next;
                    isodd = true;
                }
                p = p->next;
            }
            eventail->next = NULL;
            oddtail->next = even;
            return odd;
        }
    }
};