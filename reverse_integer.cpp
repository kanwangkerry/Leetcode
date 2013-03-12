class Solution {
public:
    int reverse(int x) {
        int origin = x;
        if(x < 0) x = -x;
        int y, result;
        result = 0;
        while(x != 0){
            result = result*10;
            result += x%10;
            x = x/10;
        }
        return origin >0?result:-result;
    }
};
