
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = n-1;
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(matrix[mid][0] == target)
                break;
            else if(matrix[mid][0] > target){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        int x = (left + right)/2;
        left = 0, right = m-1;
        while(left <= right){
            mid = (left + right)/2;
            if(matrix[x][mid] == target)
                return true;
            else if(matrix[x][mid] > target){
                right = mid -1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
};
