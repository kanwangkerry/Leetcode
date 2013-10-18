
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *steps_index = new int[n];
        int max =0;
        int j = 0;
        if(n == 1) return 0;
        steps_index[0] = A[0] + 0 > n-1 ? n-1 : A[0] + 0;
         if(steps_index[j] == n-1)
                return j+1;
        for(int i = 1 ; i < n ; ){
            max = 0;
            for(; i <= steps_index[j] ; i++){
                if(max < A[i] + i)
                    max = A[i] + i;
            }
            j++;
            steps_index[j] = (max > n-1? n-1: max);
            if(steps_index[j] == n-1)
                return j+1;
        }
        return j;
        
    }
};
