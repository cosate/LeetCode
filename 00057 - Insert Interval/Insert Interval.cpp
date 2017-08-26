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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int index = 0;
        for(; index < intervals.size(); index++)
        {
            if(intervals[index].start > newInterval.start)
                break;
        }
        intervals.insert(intervals.begin() + index, newInterval);
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
        vector<Interval> res;
        while(!temp.empty())
        {
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};