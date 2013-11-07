
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int a[120];
        for(int j = 0 ; j < n ;j ++){
            a[j] = 1;
        }
        for(int i = 1 ; i < m ; i++){
            a[0] = a[0];
            for(int j = 1 ; j < n ; j++){
                a[j] = a[j-1] + a[j];
            }
        }
        return a[n-1];
    }
};
