/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p = head;
        if(p == NULL)
            return NULL;
        
        map<RandomListNode*, int> coordin;
        int i = 0;
        while(p != NULL)
        {
            coordin[p] = i;
            p = p->next;
            ++i;
        }
        
        RandomListNode* ret = new RandomListNode(INT_MAX);
        vector<bool> exist(i);
        for(int j = 0; j < i; j++)
        {
            exist[j] = false;
        }
        
        RandomListNode* tail = ret;
        p = head;
        map<int, RandomListNode*> reversemap;
        while(p != NULL)
        {
            if(!exist[coordin[p]])
            {
                tail->next = new RandomListNode(p->label);
                tail = tail->next;
                exist[coordin[p]] = true;
                reversemap[coordin[p]] = tail;
            }
            else
            {
                tail = reversemap[coordin[p]];
            }
            if(p->random != NULL)
            {
                if(!exist[coordin[p->random]])
                {
                    tail->random = new RandomListNode(p->random->label);
                    exist[coordin[p->random]] = true;
                    reversemap[coordin[p->random]] = tail->random;
                }
                else
                {
                    tail->random = reversemap[coordin[p->random]];
                }
            }
            if(p->next != NULL)
            {
                if(!exist[coordin[p->next]])
                {
                    tail->next = new RandomListNode(p->next->label);
                    exist[coordin[p->next]] = true;
                    reversemap[coordin[p->next]] = tail->next;
                }
                else
                {
                    tail->next = reversemap[coordin[p->next]];
                }
            }
            p = p->next;
        }
        return ret->next;
    }
};