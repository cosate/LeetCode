/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode * res = NULL;
        if(node == NULL)
            return res;
		if (mm.count(node) == 0)
		{
			res = new UndirectedGraphNode(node->label);
			mm[node] = res;
		}
		else
			res = mm[node];
		for (int i = 0; i < node->neighbors.size(); i++)
		{
			if (mm.count(node->neighbors[i]) == 0)
			{
				UndirectedGraphNode* temp = cloneGraph(node->neighbors[i]);
				res->neighbors.push_back(temp);
				mm[node->neighbors[i]] = temp;
			}
			else
			{
				res->neighbors.push_back(mm[node->neighbors[i]]);
			}
		}
		return res;
	}
	map<UndirectedGraphNode*, UndirectedGraphNode*> mm;
};