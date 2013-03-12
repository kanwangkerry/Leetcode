class Solution {
public:
    string longestPalindrome(string s) {
        int result[1001][1001];
        int len = s.length();
        for(int j = 0 ; j < len; j++){
            for(int i = 0 ; i < len-j ;i++){
        
                if(j == 0) result[i][i+j] = 1;
                else if(j == 1 && s[i] == s[i+j]) result[i][i+j] = 2;
                else if(j == 1 && s[i] != s[i+j]) result[i][i+j] = 1;
                else if(s[i] == s[i+j] && result[i+1][i+j-1] == j-1)
                   result[i][i+j] = j+1;
                else {
                    result[i][i+j] = (result[i+1][i+j] > result[i][i+j-1]? result[i+1][i+j]:result[i][i+j-1]);
                }
            }
        }
        
        int i;
        for(i = 0; i + result[0][len-1] < len; i++){
            if(result[i][i+result[0][len-1]-1] == result[0][len-1]) break;
        }
       
        return s.substr(i, result[0][len-1]);
    }
};
