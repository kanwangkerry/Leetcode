class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        int flag = 1;
        int d10000 = 0;
        if(dividend < 0 || divisor <0){
            if(dividend >0 && divisor <0){
                flag = -1;
                dividend = -dividend;
            }
            if(divisor >0 && dividend <0){
                flag = -1;
                divisor = -divisor;
            }
            if(divisor > -10000){
                for(int i = 0 ; i < 10000 ;i ++){
                    d10000 += divisor;
                }
            }
            
            while(1){
                if(d10000 != 0 && dividend <= d10000){
                    dividend -= d10000;
                    result += 10000;
                }
                else if(dividend <= divisor){
                    dividend -= divisor;
                    result += 1;
                }
                else break;
            }
            return flag>0?result:-result;
        }
        else{

            if(divisor < 10000){
                for(int i = 0 ; i < 10000 ;i ++){
                    d10000 += divisor;
                }
            }
            
            while(1){
                if(d10000 != 0 && dividend >= d10000){
                    dividend -= d10000;
                    result += 10000;
                }
                else if(dividend >= divisor){
                    dividend -= divisor;
                    result += 1;
                }
                else break;
            }
            return flag>0?result:-result;
            
        }
        
    }
};
