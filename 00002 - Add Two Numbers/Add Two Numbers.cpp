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
        ListNode* p1 = l1;
        int dg1 = 0;
        ListNode* p2 = l2;
        int dg2 = 0;
        ListNode* result = new ListNode(0);
        ListNode* pResult = result;
        int temp = 0;
        //第一个数的位数
        while(p1 != NULL)
        {
            dg1++;
            p1 = p1->next;
        }
        //第二个数的位数
        while(p2 != NULL)
        {
            dg2++;
            p2 = p2->next;
        }
        //补齐
        if(dg1 > dg2)
        {
            p2=l2;
            for(int i = 1; i < dg2; i++)
            {
                p2 = p2->next;
            }
            for(int i = dg2; i < dg1; i++)
            {
                p2->next = new ListNode(0);
                p2 = p2->next;
            }
        }
        else
        {
            p1=l1;
            for(int i = 1; i < dg1; i++)
            {
                p1 = p1->next;
            }
            for(int i = dg1; i < dg2; i++)
            {
                p1->next = new ListNode(0);
                p1 = p1->next;
            }
        }
        
        p1 = l1;
        p2 = l2;
        result->val = (temp + p1->val + p2->val)%10;
        temp = (temp + p1->val + p2->val)/10;
        p1 = l1->next;
        p2 = l2->next;
        while(p1 != NULL && p2 != NULL)
        {
            pResult->next = new ListNode((temp + p1->val + p2->val)%10);
            temp = (temp + p1->val + p2->val)/10;
            pResult = pResult->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1 == NULL && p2 == NULL && temp != 0)
        {
            pResult->next = new ListNode(temp);
        }
        return result;
    }
};