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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return NULL;
        int length = 0;
        ListNode* p = head;
        ListNode* q = head;
        while(p != NULL)
        {
            length++;
            p = p->next;
        }
        p = head;
        int x = 1, y = 1;
        if(m == 1)
        {
            while(q != NULL && y < n)
            {
                q = q->next;
                y++;
            }
            ListNode* temp = q->next;
            ListNode* res = reverse(p,q);
            p->next = temp;
            return res;
        }
        else if(n == length)
        {
            ListNode* temp = p;
            while(temp != NULL && x < m-1)
            {
                temp = temp->next;
                x++;
            }
            p = temp->next;
            while(q != NULL && y < n)
            {
                q = q->next;
                y++;
            }
            temp->next = reverse(p,q);
            return head;
        }
        else
        {
            ListNode* temp1 = p;
            while(temp1 != NULL && x < m-1)
            {
                temp1 = temp1->next;
                x++;
            }
            p = temp1->next;
            
            while(q != NULL && y < n)
            {
                q = q->next;
                y++;
            }
            ListNode* temp2 = q->next;
            temp1 -> next = reverse(p,q);
            p->next = temp2;
            return head;
        }
    }
    
    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        if(head == tail)
            return head;
        else
        {
            ListNode* p = head;
            ListNode* q = p->next;
            ListNode* r = q->next;
            p->next = NULL;
            while(r!=tail->next)
            {
                q->next = p;
                p = q;
                q = r;
                r = r->next;
            }
            q->next = p;
            return q;
        }
    }
};