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
        if (intervals.size() == 0) return {};

        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> result;
        int start = 0;
        while (start < intervals.size()) {
            int stop = start;
            int max_val = intervals[stop].end;
            while (stop + 1 < intervals.size() && max_val >= intervals[stop + 1].start) {
                stop += 1;
                max_val = max(max_val, intervals[stop].end);
            }

            result.push_back(Interval(intervals[start].start, max_val));
            start = stop + 1;
        }
        return result;
    }

    static bool comp(Interval &a, Interval &b) {
        return a.start < b.start;
    }
};
