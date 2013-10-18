
public class Solution {
    int cutResult[][];
    boolean palindrome[][];
    public int minCut(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        //init
        int n = s.length();
        int min = n;
        int sum = 0;
        cutResult = new int[n+1][n+1];
        palindrome = new boolean[n+1][n+1];
            
        for(int l = 1; l <= n ; l++){
            for(int i = 0 ; i <= n-l ;i++){
                palindrome[i][i+l] = isPalindrome(s.substring(i, i+l));
                if(palindrome[i][i+l]){
                    cutResult[i][i+l] = 0;
                    continue;
                 }
                min = l-1;
                for(int k = 1 ; k < l ; k++){
                    sum = cutResult[i][i+k] + cutResult[i+k][i+l];
                    if(sum < min)
                        min = sum;
                }
                cutResult[i][i+l] = 1+min;
            }
        }
        
        return cutResult[0][n];
    }
    
    boolean isPalindrome(String s){
        String rs = new String(new StringBuilder(s).reverse().toString());
        return rs.equals(s);
    }
}
