
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *rightHigh = new int[n];
        int max = 0;
        if( n < 3) return 0;
        rightHigh[n-1] = 0;
        for(int i = n-2; i >= 0 ; i--){
            if(max < A[i+1])
                max = A[i+1];
            rightHigh[i] = max;
        }
        max = 0;
        int sum = 0;
        for(int i = 1 ; i< n ; i++){
            if(max < A[i -1])
                max = A[i-1];
            if(A[i] < max && A[i] < rightHigh[i]){
                sum += (max < rightHigh[i] ? max : rightHigh[i]) - A[i];
            }
        }
        return sum;
    }
};
