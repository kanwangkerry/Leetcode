class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 1) return true;
        bool *jump = new bool[n];
        jump[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            int max = A[i];
            max = max > (n-1 -i)?(n-1 - i):max;
            jump[i] = false;
            for(int j = 1; j <= max; j++){
                if(jump[i+j]){
                    jump[i] = true;
                    break;
                }               
            }
        }
        return jump[0];
    }

};
