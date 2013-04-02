class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 1) return 0;
        int *jump = new int[n];
        jump[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int max = A[i];
            max = max > (n-1-i)?(n-1-i):max;
            int min = n + 1;
            for(int j = 1; j <= max; j++){
                if(min > jump[i+j]+1)
                    min = jump[i+j]+1;
            }
            jump[i] = min;
        }
        return jump[0];

        
    }
};
