
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct less_than_key
{
    inline bool operator() (const Interval& i1, const Interval& i2)
    {
        return (i1.start < i2.start);
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(intervals.begin(), intervals.end(), less_than_key());
        vector<Interval> results;
        int n = intervals.size();
        if(n == 0)
            return results;
        int index = 0;
        results.push_back(intervals[0]);
        for(int i = 1 ; i < n ;i ++){
            if(intervals[i].start <= results[index].end){
                results[index].end = intervals[i].end > results[index].end ? intervals[i].end : results[index].end;
            }
            else{
                results.push_back(Interval(intervals[i].start, intervals[i].end));
                index++;
            }
        }
        return results;
    }
};
