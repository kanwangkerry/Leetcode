
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start =0, end = 0;
        int n = gas.size();
        int sum = 0;
        while(true){
            if(sum + gas[end] - cost[end] >= 0){
                sum = sum + gas[end] - cost[end];
                end ++;
                if(end == n)
                    end = 0;
                if(end == start)
                    break;
            }
            else{
                start --;
                if(start == -1)
                    start = n-1;
                sum += gas[start] - cost[start];
                if(end == start)
                    break;
            }
        }
        if(sum <0)
            return -1;
        else return start;
    }
};
