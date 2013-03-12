class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s[0] == 0 && p[0] == 0) return true;
        if(s[0] != 0 && p[0] == 0) return false;
        if(p[1] != '*'){
            if(s[0] == 0) return false;
            if(p[0] == s[0] || p[0] == '.')
                return isMatch(s+1, p+1);
            else return false;
        }
        else{
            int len = strlen(s);
            bool x = isMatch(s,p+2);
            if(x) return x;
            for(int i = 0 ; i < len; i++ ){
                if(s[i] == p[0] || p[0] == '.'){
                    x = isMatch(s+i+1, p+2);
                    if(x) return true;
                }
                else{
                    x = isMatch(s+i, p+2);
                    break;
                }
            }
            return x;
            
        }
        
    }
};
