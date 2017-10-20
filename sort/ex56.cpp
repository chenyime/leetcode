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
        if (intervals.size() == 1 || intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        int i = 1;
        res.push_back(intervals[0]);
        while (i < intervals.size()) {
            if (res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end, intervals[i].end);
            i++;
        }
        return res;
    }
    
    static bool compare(Interval a1, Interval a2) {
        return a1.start < a2.start;
    }
};