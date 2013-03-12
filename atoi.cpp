class Solution {
public:
    int atoi(const char *str) {
        int begin, end;
        int len = strlen(str);
        int i;
        for(i = 0 ; i < len ; i++){
            if(str[i] != ' ') break; 
        }
        begin = i;
        if(str[begin] != '+' && str[begin] != '-' && (str[begin] < '0' || str[begin] > '9'))
            return 0;
        for(i = begin+1 ; i < len; i++){
            if(str[i] < '0' || str[i]> '9') break;
        }
        end = i;
        int flag = 1;
        int result1=0, result2=0;
        if(str[begin] == '+'){
            flag = 1;
            begin ++;
        }
        if(str[begin] == '-'){
            flag = -1;
            begin ++;
        }
        int index1=0, index2= 0;
        if(end-begin > 10) return flag>0?2147483647:-2147483648;
        for(i = begin ; i< end; i++){
            if(result1 < 100000){
                index1++;
                result1 = result1*10;
                result1 += (str[i]-'0');
            }
            else{
                index2++;
                result2 = result2*10;
                result2 += str[i]-'0';
            }
        }
        int final_result = pow(10, index2)*result1+result2;
        if(end-begin < 10) return flag>0?final_result:-final_result;
        
        if(flag > 0){
            if(result1 > 214748) return 2147483647;
            else if(result1 < 214748) return final_result;
            else{
                if(result2 > 3647) return 2147483647;
                else return final_result;
            }
        }
           if(flag < 0){
            if(result1 > 214748) return -2147483648;
            else if(result1 < 214748) return -final_result;
            else{
                if(result2 > 3648) return -2147483648;
                else return -final_result;
            }
        }
    
    }
};
