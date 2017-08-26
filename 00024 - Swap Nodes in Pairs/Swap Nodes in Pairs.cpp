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
    ListNode* swapPairs(ListNode* head) {
        ListNode * temp = NULL;
    	ListNode * indice = head;
    	if(head != NULL && head->next != NULL)
    	{
    	    head = head->next;
    	}
    	/*else if(head != NULL && head->next == NULL)
    	{
    	    return head;
    	}*/
    	while (indice != NULL)
    	{
    	    if(indice->next != NULL)
    	    {
        		temp = indice->next->next;
        		indice->next->next = indice;
        		if (temp != NULL)
        		{
        		    if(temp->next != NULL)
        		    {
        			    indice->next = temp->next;
        		    }
        		    else
        		    {
        		        indice->next = temp;
        		    }
        		}
        		else
        		{
        			indice->next = NULL;
        		}
        		indice = temp;
    	    }
    	    else
    	    {
    	        return head;
    	    }
    	}
    	return head;
    }
};