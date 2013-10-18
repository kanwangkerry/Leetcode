
public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<Integer> row = new ArrayList<Integer>(rowIndex + 1);
        row.add(Integer.valueOf(1));
        for(int i = 1 ; i <= rowIndex ; i++){
            row.add(row.get(i-1));
            for(int j = i-1; j > 0; j --){
                row.set(j, row.get(j) + row.get(j-1));
            }
        }
        return row;
        
    }
}
