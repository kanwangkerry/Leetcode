
class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = x;
        right = x/2<std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);
        while(left <= right){
            int mid = (left + right)/2;
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return right;
    }
};
