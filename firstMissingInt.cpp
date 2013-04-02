class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0 ; i < n ; i++){
            if(A[i] < -n) A[i] = -A[i] +n;
            if(A[i] <= 0) A[i] += 2*n;
        }
        for(int i = 0 ; i < n ;i++){
            int temp = A[i]<0?-A[i]:A[i];
            if(temp <= n){
                if(A[temp-1] > 0)
                    A[temp-1] =  0 - A[temp-1];
            }
        }
        int i;
        for( i = 0 ; i< n ; i++){
            if(A[i]>0) break;
        }
        return i+1;
        
    }
};
