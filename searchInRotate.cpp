class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot = A[0];
        int left = 1, right = n-1, mid = 0;
        while(left <= right){
            mid = (left+right)/2;
            if(A[mid] > pivot && A[mid+1] < pivot)
                break;
            else if(A[mid] > pivot && A[mid+1] > pivot){
                left = mid+1;
            }
            else if(A[mid] < pivot && A[mid+1] < pivot){
                right = mid-1;
            }
        }
        if(left > right)
            mid = -1;
        if(left > right && A[0] > A[n-1])
            mid = 0;
       
       int index = mid+1;
       left = 0, right = n-1, mid = 0;
       while(left <= right){
           mid = (left+right)/2;
           if(mid < n-index)
                mid = mid+index;
            else 
                mid = mid-(n-index);
           if(A[mid] == target)
                return mid;
            else if(A[mid] < target){
                left = (left+right)/2+1;
                
            }
            else{
                right = (left+right)/2-1;
                
            }
            
       }
       if(left>right)return -1;
       return mid;
        
    }
};
