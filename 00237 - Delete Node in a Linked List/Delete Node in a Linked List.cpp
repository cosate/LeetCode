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
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        ListNode* q = node;
        int i = 0;
        while((p->next) != NULL)
        {
            if(i>0)
                q = q->next;
            p->val = p->next->val;
            p = p->next;
            i++;
        }
        q->next = NULL;
        delete p;
    }
};