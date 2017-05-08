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
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int overlap=0,i=0,n=intervals.size();
        for(i=0;i<n;i++){
            if(newInterval.end < intervals[i].start)
                break;
            else if(intervals[i].end < newInterval.start)
                {}
            else{
                newInterval.start=min(intervals[i].start,newInterval.start);
                newInterval.end=max(intervals[i].end,newInterval.end);
                overlap++;
            }
        }
        if(overlap>0)
            intervals.erase(intervals.begin()+i-overlap,intervals.begin()+i);
        intervals.insert(intervals.begin()+i-overlap,newInterval);
        return intervals;
    }
};
