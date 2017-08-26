class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> used(numCourses, false);
        vector<int> indegree(numCourses, 0);
        map<int, vector<int>> mm;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            indegree[prerequisites[i].first]++;
            if(mm.count(prerequisites[i].second))
                mm[prerequisites[i].second].push_back(prerequisites[i].first);
            else
            {
                vector<int> vec;
                mm[prerequisites[i].second] = vec;
                mm[prerequisites[i].second].push_back(prerequisites[i].first);
            }
        }
        for(int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for(; j < numCourses; j++)
            {
                if(!used[j] && indegree[j] == 0)
                {
                    break;
                }
            }
            if(j == numCourses)
                return false;
            used[j] = true;
            for(auto val : mm[j])
                indegree[val]--;
        }
        return true;
    }
};