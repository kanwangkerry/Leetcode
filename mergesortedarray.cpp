
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = m-1, j = n-1;
        int index = n+m-1;
        while(i >=0 && j >= 0){
            if(A[i] >= B[j]){
                A[index--] = A[i];
                i--;
            }
            else{
                A[index--] = B[j];
                j--;
            }
        }
        while(i >=0){
            A[index--] = A[i--];
        }
        while(j >= 0){
            A[index--] = B[j--];
        }
    }
};
