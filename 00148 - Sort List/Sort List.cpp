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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        
        int len = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            len++;
            p = p->next;
        }
        ListNode* begin = head;
        ListNode* middle = begin;
        for(int i = 0; i < len/2-1; i++)
        {
            middle = middle->next;
        }
        ListNode* q = middle;
        middle = middle->next;
        q->next = NULL;
        return merge(sortList(begin), sortList(middle));
    }
    ListNode* merge(ListNode* first, ListNode* second)
    {
        if(first == NULL)
            return second;
        if(second == NULL)
            return first;
        ListNode* res = (first->val < second->val) ? first : second;
        if(first->val < second->val)
            res->next = merge(first->next, second);
        else
            res->next = merge(first,second->next);
        return res;
    }
};