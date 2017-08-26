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
    bool hasCycle(ListNode *head) {
        ListNode * one = head;
    	ListNode * two = head;
    	while (one != NULL && two != NULL)
    	{
    		one = one->next;
    		if (two->next != NULL)
    			two = two->next->next;
    		else
    			return false;
    		if (one != NULL && two != NULL && one->val == two->val)
    			return true;
    	}
    	return false;
    }
};