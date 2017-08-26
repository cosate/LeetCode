class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size();
        int result = 0;
        unordered_map<int,int> m;
        for(int i = 0; i<len; i++)
        {
            for(int j = 0; j<len; j++)
            {
                int x = points[i].first - points[j].first;
                int y = points[i].second - points[j].second;
                int dis = x*x + y*y;
                m[dis]++;
            }
            unordered_map<int,int>::iterator it;
            for(it = m.begin(); it != m.end(); it++)
            {
                int i = it->second;
                result += i*(i-1);
            }
            m.clear();
        }
        return result;
    }
};