class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int i;
        if(len == 0) return true;
        if(s[0] == '('){
            for(i = 1 ; i < len ;i++){
                if(s[i] == ')' && isValid(s.substr(1, i -1)) && isValid(s.substr(i+1, len - i -1)))
                    return true;
            }
            return false;
        }
        if(s[0] == '['){
            for(i = 1 ; i < len ;i++){
                if(s[i] == ']' && isValid(s.substr(1, i -1)) && isValid(s.substr(i+1, len - i -1)))
                    return true;
            }
            return false;
        }
        if(s[0] == '{'){
            for(i = 1 ; i < len ;i++){
                if(s[i] == '}' && isValid(s.substr(1, i -1)) && isValid(s.substr(i+1, len - i -1)))
                    return true;
            }
            return false;
        }
        
    }
};
