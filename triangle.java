
public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = triangle.size();
        ArrayList<Integer> rowResult = new ArrayList<Integer>(n);
        for(int i = 0 ; i < n ;i ++){
            rowResult.add(triangle.get(n-1).get(i));
        }
        int temp = 0;
        for(int i = n-2; i>=0; i--){
            for(int j = 0 ; j <= i; j++){
                temp = rowResult.get(j) < rowResult.get(j+1) ? rowResult.get(j) : rowResult.get(j+1);
                rowResult.set(j, temp + triangle.get(i).get(j));
            }
        }
        return rowResult.get(0);
    }
}
