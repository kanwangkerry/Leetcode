
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
    struct pred
    {
        bool operator()(Interval const & a, Interval const & b) const
        {
            return a.start < b.start;
        }
    };
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = intervals.size();
        if(n == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int iStart= -1, iEnd = -1;
        for(int i = 0 ; i < n ; i++){
            if(intervals[i].start <= newInterval.start)
                iStart = i;
            if(intervals[i].start <= newInterval.end)
                iEnd = i;
        }
            if(iStart >=0 && intervals[iStart].end >= newInterval.start){
                newInterval.start = intervals[iStart].start;
            }
            else{
                iStart = iStart +1;
            }
        if(iEnd >= 0 && intervals[iEnd].end > newInterval.end){
            newInterval.end = intervals[iEnd].end;
        }
        if(iStart < n && iStart <= iEnd)
            intervals.erase(intervals.begin()+iStart, intervals.begin()+iEnd+1);
        intervals.insert(intervals.begin()+iStart, newInterval);
        
        return intervals;
    }
};
