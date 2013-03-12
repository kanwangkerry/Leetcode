class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int half = (m+n+1)/2;
        int x= findXth(A, m, B, n, half);
        int y;
        if((m+n)%2 == 0){
            y=findXth(A, m, B, n, half+1);
            return (x+y)/(double) 2;        
        }
        else return x;
        
        
    }
    int findXth(int A[], int m, int B[], int n, int x){
        if(m == 0) return B[x-1];
        if(n == 0) return A[x-1];
        if(x == 1) return A[0] < B[0]?A[0]:B[0];
        int z = m>n?n:m;
        int y = x/2;
        y = y > z ? z : y;
        if(A[y-1] < B[y-1])
            return findXth(A + y, m-y, B, n, x-y);
        else if(A[y-1] > B[y-1])
            return findXth(A, m, B+y, n-y, x-y);
        else return A[y-1];
    }
};
