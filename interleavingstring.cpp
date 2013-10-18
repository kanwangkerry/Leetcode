
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        bool** result;
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1 == 0)
            return s2 == s3;
        if(n2 == 0)
            return s1 == s3;
        if(n1 + n2 != n3)
            return false;
        result = new bool*[n1+1];
        for(int i = 0 ; i <= n1 ; i ++){
            result[i] = new bool[n2+1];
        }
        for(int i = 1 ; i <= n1; i++){
            result[i][0] = (s1[i-1] == s3[i-1]);
        }
        for(int i = 1 ; i <= n2; i++){
            result[0][i] = (s2[i-1] == s3[i-1]);
        }
        for(int i = 1; i <= n1; i ++){
            for(int j =1 ; j <= n2 ; j++){
                result[i][j] = (result[i-1][j] && (s1[i-1] == s3[i+j-1])) || 
                (result[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return result[n1][n2];
        
    }
    
};
