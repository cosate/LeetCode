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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        vector<ListNode*> vec;
        int n = 0;
        while(q != NULL)
        {
            n++;
            if(n%k == 0)
            {
                ListNode* temp = q->next;
                vec.push_back(reverse(p,q));
                p = temp;
                q = temp;
            }
            else
                q = q->next;
        }
        vec.push_back(p);
        for(int i = 0; i<vec.size()-1; i++)
        {
            ListNode* p = vec[i];
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = vec[i+1];
        }
        return vec[0];
    }
    
    ListNode* reverse(ListNode* head,ListNode* tail)
    {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        if(head != tail)
        {
            ListNode* p = head;
            ListNode* q = p->next;
            ListNode* r = q->next;
            p->next = NULL;
            while(r != tail->next)
            {
                q->next = p;
                p = q;
                q = r;
                r = r->next;
            }
            q->next = p;
            return q;
        }
        else
        {
            head->next = NULL;
            return head;
        }
        
    }
};