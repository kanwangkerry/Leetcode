
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        int len = 0;
        int last = 0;
        while(s[i] != 0){
            if(s[i] == ' '){
                if(len != 0)
                last = len;
                len = 0;
                i++;
            }
            else{
                len ++;
                i++;
            }
        }
        if(len != 0)
          last = len;
        return last;
        
    }
};
