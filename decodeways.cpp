
class Solution {
public:
    bool ableToDecode2(string s, int begin){
        if(begin == s.size() -1 || begin < 0)
            return false;
        if(s[begin] == '1' || (s[begin] == '2' && s[begin+1] <= '6' && s[begin+1] >= '0'))
            return true;
        else return false;
    }

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n ==0)
            return 0;
        int *result = new int[n];
        for(int i = 0 ; i < n ; i++)
            result[i] = 0;
            
        if(s[n-1] == '0'){
            result[n-1] = 0;
        }
        else{
            result[n-1] = 1;
        }
        if(s.size() >= 2 && ableToDecode2(s, n-2)){
            result[n-2] = 1 + result[n-1];
        }
        else if(n >= 2 && !ableToDecode2(s, n-2)){
            if(s[s.size()-2] == '0')
                result[n-2] = 0;
            else
                result[n-2] = result[n-1];
        }
        for(int i = n - 3; i >= 0 ; i--){
            if(s[i] == '0'){
                result[i] = 0;
                continue;
            }
            if(ableToDecode2(s, i)){
                result[i] = result[i+1] + result[i+2];
            }
            else
                result[i] = result[i+1];
        }
        return result[0];
        
    }

};
