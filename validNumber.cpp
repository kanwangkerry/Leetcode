
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while(s[i] != 0){
            if(s[i] == ' ')
                i++;
            else
                break;
        }
        bool no_point = false;
        bool no_e = false;
        bool num_begin = false;
        bool no_minus = false;
        //number start here
        while(s[i] != 0){
            if(s[i] == ' ')
                break;
            if(s[i] == '.' ){
                if(no_point == false){
                    no_point = true;
                    no_minus = true;
                }
                else return false;
            }
            else if(s[i] == '-' || s[i] == '+'){
                if(!no_minus){
                    no_minus = true;
                }
                else
                    return false;
            }
            else if(s[i] == 'e'){
                if(!no_e && num_begin){
                    no_e = true;
                    no_point = true;
                    num_begin = false;
                    no_minus = false;
                }
                else return false;
                
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                num_begin = true;
                no_minus = true;
            }
            else
                return false;
            i++;
        }
        
        if(num_begin == false)
            return false;
        
        while(s[i] != 0){
            if(s[i] == ' ')
                i++;
            else
                return false;
        }
        return true;
    }
};
