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
    ListNode *detectCycle(ListNode *head) {
        ListNode* curr = head;
        while(curr != NULL)
        {
            if(find(head, curr))
                return curr->next;
            curr = curr->next;
        }
        return NULL;
    }
    
    bool find(ListNode* head, ListNode* target)
    {
        ListNode* p = head;
        if(p == NULL)
            return false;
        while(p != target)
        {
            if(p == target->next)
                return true;
            p = p->next;
        }
        if(p->next == target)
            return true;
        return false;
    }
};