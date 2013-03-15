class Solution {
public:
    int binarySearchLast(int A[], int n, int target)
    {
        int l = -1, u = n;
        while (l + 1 != u)
        {
            int mid = l + (u-l)/2;
            if (A[mid] <= target)
                l = mid;
            else u = mid;
        }
        int p = l;
        if (p < 0 || A[p] != target)
            p = -1;
        return p;
    }
    
    int binarySearchFirst(int A[], int n, int target)
    {
        int l = -1, u = n;
        while (l+1 != u)
        {
            int mid = l + (u-l)/2;
            if (A[mid] < target)
                l = mid;
            else u = mid;
        }
        int p = u;
        if (p >= n || A[p] != target)
            p = -1;
        return p;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if (n == 0) return vector<int>(2, -1);
        
        int start = binarySearchFirst(A, n, target);
        if (start == -1)
            return vector<int>(2, -1);
            
        int end = binarySearchLast(A, n, target);
        
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};
