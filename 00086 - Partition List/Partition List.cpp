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
    ListNode* partition(ListNode* head, int x) {
        ListNode* min = NULL;
        ListNode* max = NULL;
        ListNode* p = head;
        ListNode* mintail = NULL;
        ListNode* maxtail = NULL;
        
        if(head == NULL)
            return NULL;
        else if(head->val < x)
        {
            min = head;
            while(p->next != NULL && p->next->val < x)
            {
                p = p->next;
            }
            mintail = p;
            max = p->next;
            maxtail = p->next;
        }
        else
        {
            max = head;
            while(p->next != NULL && p->next->val >= x)
            {
                p = p->next;
            }
            maxtail = p;
            min = p->next;
            mintail = p->next;
        }
        if(min == NULL)
            return max;
        if(max == NULL)
            return min;
        p = p->next->next;     
        while(p != NULL)
        {
            if(p->val < x)
            {
                mintail->next = p;
                mintail = mintail->next;
            }
            else
            {
                maxtail->next = p;
                maxtail = maxtail->next;
            }
            p = p->next;
        }
        maxtail->next = NULL;
        mintail->next = max;
        return min;
    }
};