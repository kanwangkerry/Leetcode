
class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        if(n == 0)
            return 1;
        if(n%2 == 0){
            double y = pow(x, n/2);
            return y*y;
        }
        else{
            double y = pow(x, (n-1)/2);
            return y*y*x;
        }
        
    }
};
