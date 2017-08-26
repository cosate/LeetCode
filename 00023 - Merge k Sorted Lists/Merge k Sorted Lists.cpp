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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        return merge(lists, 0, len-1);
    }
    
    ListNode* merge(vector<ListNode*>& lis, int begin, int end)
    {
        if(begin > end)
            return NULL;
        else if(begin == end)
            return lis[begin];
        else if(end-begin == 1)
            return merge2Lists(lis[begin], lis[end]);
        else
        {
            return merge2Lists(merge(lis, begin, begin+(end-begin)/2), merge(lis, begin+(end-begin)/2+1, end));
        }
    }
    
    ListNode* merge2Lists(ListNode* first, ListNode* second)
    {
        ListNode* res = NULL;
        if(first == NULL)
            return second;
        if(second == NULL)
            return first;
        if(first->val < second->val)
        {
            res = first;
            first = first->next;
            res->next = merge2Lists(first,second);
        }
        else
        {
            res = second;
            second = second->next;
            res->next = merge2Lists(first,second);
        }
        return res;
    }
};