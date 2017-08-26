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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        int carry = 0;
        stack<int> result;
        ListNode* p = l1;
        ListNode *q = l2;
        while(p != NULL)
        {
            s1.push(p->val);
            p = p->next;
        }
        while(q != NULL)
        {
            s2.push(q->val);
            q = q->next;
        }
        while(!s1.empty() && !s2.empty())
        {
            int s = (s1.top()+s2.top()+carry)%10;
            carry = (s1.top()+s2.top()+carry)/10;
            result.push(s);
            s1.pop();
            s2.pop();
        }
        if(s1.empty() && s2.empty())
        {
            if(carry!=0)
                result.push(carry);
        }
        else if(s1.empty())
        {
            while(!s2.empty())
            {
                int s = (s2.top()+carry)%10;
                carry = (s2.top()+carry)/10;
                result.push(s);
                s2.pop();
            }
            if(carry!=0)
                result.push(carry);
        }
        else
        {
            while(!s1.empty())
            {
                int s = (s1.top()+carry)%10;
                carry = (s1.top()+carry)/10;
                result.push(s);
                s1.pop();
            }
            if(carry!=0)
                result.push(carry);
        }
        ListNode* b = new ListNode(result.top());
        result.pop();
        ListNode* temp = b;
        while(!result.empty())
        {
            ListNode * t = new ListNode(result.top());
            temp->next = t;
            temp = temp->next;
            result.pop();
        }
        return b;
    }
};