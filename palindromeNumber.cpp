
class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(x < 0)
            return false;
        return x == reverseInt(x);
       
    }
    
    int reverseInt(int x){
        int y = 0;
        while(x > 0){
            y*=10;
            y += x%10;
            x = x/10;
        }
        return y;
    }
};
