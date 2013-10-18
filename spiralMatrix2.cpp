
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int side = 0;
        int start = 1;
        vector<int> temp(n, 0);
        vector<vector<int> > result(n, temp);
        while(side < n-1){
            start = fillCircle(start, side/2, n, result);
            side += 2;
        }
        if(n%2 == 1){
            result[n/2][n/2] = start;
        }
        return result;
    }
    
    int fillCircle(int start, int side, int len, vector<vector<int> > &result){
        for(int i = 0 ; i < len -side*2 -1; i++){
            result[side][side + i] = start;
            start ++;
        }
        for(int i = 0 ;i < len -side*2 -1; i ++){
            result[side + i][len - side -1] = start;
            start ++;
        }
        for(int i = 0 ;i < len -side*2 -1; i ++){
            result[len-side-1][len-side - 1 - i] = start;
            start ++;
        }
        for(int i = 0 ;i < len -side*2 -1; i ++){
            result[len - side -1-i][side] = start;
            start ++;
        }
        return start;
    }
};
