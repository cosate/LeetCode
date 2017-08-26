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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
			return NULL;
		ListNode* p = head;
		ListNode* q = head;
		int len = 0;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		p = head;
		k = k%len;
		if (k == 0)
			return head;
		int i = 0;
		while (q->next != NULL)
		{
			if (i >= k)
				p = p->next;
			q = q->next;
			i++;
		}
		ListNode* res = p->next;
		q->next = head;
		p->next = NULL;
		return res;
    }
};