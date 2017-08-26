class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> used(numCourses, false);
        vector<int> indegree(numCourses, 0);
        vector<int> res;
        map<int, vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i].first]++;
            if(graph.count(prerequisites[i].second))
                graph[prerequisites[i].second].push_back(prerequisites[i].first);
            else
            {
                vector<int> vec;
                graph[prerequisites[i].second] = vec;
                graph[prerequisites[i].second].push_back(prerequisites[i].first);
            }
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for(; j < numCourses; j++)
            {
                if(!used[j] && indegree[j] == 0)
                    break;
            }
            if(j == numCourses)
            {
                res.clear();
                return res;
            }
            used[j] = true;
            res.push_back(j);
            for(auto val : graph[j])
                indegree[val]--;
        }
        return res;
    }
};