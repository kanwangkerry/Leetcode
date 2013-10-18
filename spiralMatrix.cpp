
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = matrix.size();
        vector<int> result;
        if(n == 0) 
            return result;
        int m = matrix[0].size();
        int top = 0, left = 0, right = m-1, bot = n-1;

        bool flag = true;
        while(flag){
            flag = false;
            for(int i = left; i <= right && left <= right && top <= bot; i++){
                flag = true;
                result.push_back(matrix[top][i]);
            }
            top ++;
            for(int i = top; i <= bot && left <= right && top <= bot; i++){
                flag = true;
                result.push_back(matrix[i][right]);
            }
            right --;
            for(int i = right; i >= left && left <= right && top <= bot; i--){
                flag = true;
                result.push_back(matrix[bot][i]);
            }
            bot --;
            for(int i = bot; i >= top && left <= right && top <= bot; i--){
                flag = true;
                result.push_back(matrix[i][left]);
            }
            left ++;
          
        }
        return result;
        
    }
};
