
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n, l, t;
        n = matrix.size();
        if(n == 0)
            return;
        if(n%2){
            l = n/2+1;
            t = n/2;
        }
        else{
            l = n/2;
            t = n/2;
        }
        int temp;
        for(int i = 0 ; i < t ; i ++){
            for(int j = 0 ; j < l ;j ++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
