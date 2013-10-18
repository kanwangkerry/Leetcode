
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size())
            return false;
        if(s1.size() == 1){
            return s1 == s2;
        }
        int n = s1.size();
        int a[26];
        for(int i = 0  ; i < 26; i++){
            a[i] = 0;
        }
        for(int i = 0 ; i < n;  i++){
            a[s1[i] - 'a'] +=1;
        }
        for(int i = 0 ; i < n; i++){
            a[s2[i] - 'a'] -= 1;
        }
        for(int i = 0 ; i < 26 ;i ++){
            if(a[i] != 0)
                return false;
        }

        for(int i = 1 ; i <= n-1 ; i++){
            string ls1 = s1.substr(0, i);
            string rs1 = s1.substr(i, n-i);
            string ls2 = s2.substr(0, i);
            string rs2 = s2.substr(i, n-i);
            string rls2 = s2.substr(0, n-i);
            string rrs2 = s2.substr(n-i, i);
            if((isScramble(ls1, ls2) && isScramble(rs1, rs2)) ||
            (isScramble(ls1, rrs2) && isScramble(rs1, rls2)))
                return true;
        }
        return false;
    }
};
