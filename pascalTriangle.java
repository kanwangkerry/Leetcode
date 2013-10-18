
public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> row = new ArrayList<Integer>();
        if(numRows == 0)
            return result;
        row.add(Integer.valueOf(1));
        result.add(row);
        for(int i = 1 ; i < numRows ; i++){
            row = new ArrayList<Integer>();
            row.add(Integer.valueOf(1));
            for(int j = 1 ; j < i ; j++){
                row.add(result.get(i-1).get(j-1) + result.get(i-1).get(j));
            }
            row.add(Integer.valueOf(1));
            result.add(row);
        }
        return result;
    }
}
