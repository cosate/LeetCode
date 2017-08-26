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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;
        while(pa != NULL)
        {
            m++;
            pa = pa->next;
        }
        while(pb != NULL)
        {
            n++;
            pb = pb->next;
        }
        if(m<n)
        {
            int k = n-m;
            pa = headA;
            pb = headB;
            for(int i = 0; i < k; i++)
            {
                pb = pb->next;
            }
            while(pa != pb)
            {
                pa = pa->next;
                pb = pb->next;
            }
            return pa;
        }
        else
        {
            int k = m-n;
            pa = headA;
            pb = headB;
            for(int i = 0; i < k; i++)
            {
                pa = pa->next;
            }
            while(pa != pb)
            {
                pa = pa->next;
                pb = pb->next;
            }
            return pa;
        }
    }
};