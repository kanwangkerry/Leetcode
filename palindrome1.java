
public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = s.length();
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
        ArrayList<String> temp;
        ArrayList<ArrayList<String>> rightResult;
        if(isPalindrome(s)){
            temp = new ArrayList<String>();
            temp.add(s);
            result.add(temp);
        }
        for(int i = 0 ; i < n-1 ; i++){
            String a = s.substring(0, i+1);
            if(isPalindrome(a)){
                rightResult = partition(s.substring(i+1, n));
                for(int k = 0 ; k < rightResult.size(); k++){
                    temp = rightResult.get(k);
                    temp.add(0, a);
                }
                result.addAll(rightResult);
            }
        }
        return result;
        
    }
    boolean isPalindrome(String s){
        String rs = new String(new StringBuilder(s).reverse().toString());
        return rs.equals(s);
    }
}
