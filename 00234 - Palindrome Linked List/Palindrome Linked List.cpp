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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            n++;
            p = p->next;
        }
        ListNode* middle = head;
        for(int i = 1; i < n/2+1; i++)
        {
            middle = middle->next;
        }
        ListNode* tail = reverse(middle);
        ListNode* begin = head;
        ListNode* end = tail;
        while(begin != NULL && end != NULL)
        {
            if(begin->val != end->val)
                return false;
            else
            {
                begin = begin->next;
                end = end->next;
            }
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(head != NULL && head->next != NULL)
        {
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
        else if(head == NULL)
            return NULL;
        else
            return head;
    }
};