/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len = intervals.size();
        vector<Interval> res;
        if(len == 0)
            return res;
        sort(intervals);
        stack<Interval> s;
        s.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start <= s.top().end)
            {
                if(intervals[i].end > s.top().end)
                    s.top().end = intervals[i].end;
            }
            else
            {
                s.push(intervals[i]);
            }
        }
        stack<Interval> temp;
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        while(!temp.empty())
        {
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
    
    void sort(vector<Interval>& vec)
    {
        int len = vec.size();
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i+1; j < len; j++)
            {
                if(vec[j].start < vec[i].start)
                {
                    int tempstart = vec[j].start;
                    int tempend = vec[j].end;
                    vec[j].start = vec[i].start;
                    vec[j].end = vec[i].end;
                    vec[i].start = tempstart;
                    vec[i].end = tempend;
                }
            }
        }
    }
};