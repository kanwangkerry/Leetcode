
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = matrix.size();
        if(n == 0)
            return;
        int m = matrix[0].size();
        bool l1 = false, c1 = false;
        for(int i = 0 ; i < n ; i++){
            if(matrix[i][0] == 0)
                c1 = true;
        }
        for(int i = 0 ; i < m ; i++){
            if(matrix[0][i] == 0)
                l1 = true;
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ;j < m ; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1 ; i < m ; i++){
            if(matrix[0][i] == 0){
                for(int j = 0 ;j < n ; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 1 ; i < n ; i++){
            if(matrix[i][0] == 0){
                for(int j = 0 ;j < m ; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(l1){
            for(int i = 0 ; i < m ; i ++){
                matrix[0][i] = 0;
            }
        }
        if(c1){
            for(int j = 0 ; j < n ; j++){
                matrix[j][0] = 0;
            }
        }
        
    }
};
