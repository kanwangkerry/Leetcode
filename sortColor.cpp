
class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int front = 0, end = n-1;
        int i = 0;
        while(A[i] == 0){
            i++;
            front ++;
        }
        while(i <= end){
            if(A[i] == 0){
                if(i  == front){
                    i++;
                    front++;
                }else{
                    A[front ++] = 0;
                    A[i++] = 1;
                }
            }
            else if(A[i] == 2){
                A[i] = A[end];
                A[end--] = 2;
            }
            else
                i++;
        }
        
    }
};
