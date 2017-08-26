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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode* p2 = head;
        int i = 0;
        while(p1->next != NULL)
        {
            if(i >= n)
            {
                p2 = p2->next;
            }
            p1 = p1->next;
            i++;
        }
        ListNode *temp = p2->next;
        if(i < n)
        {
            temp  = p2;
            p2 = p2->next;
            delete temp;
            return p2;
        }
        if(temp == NULL)
        {
            return NULL;
        }
        else if(temp->next == NULL)
        {
            p2->next = NULL;
            delete temp;
            return head;
        }
        else
        {
            p2->next = temp->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
    }
};