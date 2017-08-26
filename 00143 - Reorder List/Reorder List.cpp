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
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        if(head->next == NULL)
            return;
        map<int, ListNode*> add2sub;
        int len = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            ++len;
            add2sub[len] = p;
            p = p->next;
        }
        ListNode* ret = new ListNode(INT_MAX);
        ListNode* tail = ret;
        for(int i = 1; i <= len/2; i++)
        {
            tail->next = add2sub[i];
            tail = tail->next;
            tail->next = add2sub[len+1-i];
            tail = tail->next;
        }
        if(len%2 == 1)
        {
            tail->next = add2sub[len/2+1];
            tail = tail->next;
        }
            
        tail->next = NULL;
    }
};