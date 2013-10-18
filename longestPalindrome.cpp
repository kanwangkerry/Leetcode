
class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool result[1000][1000];
        int len = s.size();
        for(int i = 0 ; i < len -1 ; i ++){
            result[i][i] = true;
            result[i][i+1] = true;
        }
        result[len-1][len-1] = true;
        int startIndex = 0, palinLen = 1;
        for(int l = 2 ; l <= len ; l++){
            for(int i = 0 ; i <= len - l ;i ++){
                result[i][i+l] = result[i+1][i+l-1] && (s[i] == s[i+l-1]);
                if(result[i][i+l]){
                    startIndex = i, palinLen = l;
                }
            }
        }
        return s.substr(startIndex, palinLen);
    }
};
