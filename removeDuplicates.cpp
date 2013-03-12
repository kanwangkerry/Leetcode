class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 0;
        int i = 0;
        int j;
        if(n == 0) return 0;
        while(i < n){
            A[index++] = A[i++];
            while(i < n){
                for(j = 0 ; j < index ;j++){
                    if(A[j] == A[i]) break;
                }
                if(j == index) break;
                else i++;
            }            
        }
        return index;
        
    }
};
