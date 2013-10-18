
public class Solution {
    public boolean isPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int i = 0, j = s.length() -1;
        if(j == -1) return true;
        while(true){
            while( i < s.length() && ! validCh(s.charAt(i))){
                i++;
            }
            while(j >= 0 && ! validCh(s.charAt(j))){
                j--;
            }
            if(i > j) break;
            if(s.charAt(i) == s.charAt(j) || s.charAt(i) == s.charAt(j) + 'A' - 'a' ||
            s.charAt(i) == s.charAt(j) + 'a' - 'A'){
                i++; j--;
            }
            else
                return false;
        }
        return true;
    }
    boolean validCh(char x){
        return (x >= 'A' && x <='Z') || (x >= 'a' && x <= 'z') || (x>='0' && x <= '9');
    }
}
