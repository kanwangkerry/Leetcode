class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;
        int divide = nRows *2 -2;
        int len = s.length();
        char *result = new char[len+1];
        int index = 0;
        int head = 0;
        for(int i = head; i < len ; i = i + divide){
            result[index++] = s[i];
        }
        for(int j = 1 ; j < nRows - 1; j++){
            head = j;
            for(int i = head; i < len; i= (((i-head)%divide == 0)?(i+2*nRows-2*head-2):(i+head*2)))
                result[index++] = s[i];
        }
        
        head = nRows -1;
        for(int i = head ; i < len; i=i+divide){
            result[index++] = s[i];
        }
        result[len] = 0;
        return result;
        
    }
};
