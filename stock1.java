
public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = prices.length;
        if(n == 0)
            return 0;
        int max = 0, currentMin = prices[0];
        int tempD;
        for(int i = 1 ;  i < n ; i++){
            if(prices[i] >= currentMin){
                tempD = prices[i] - currentMin;
                if(max < tempD)
                    max = tempD;
            }
            else{
                currentMin = prices[i];
            }
            
        }
        return max;
    }
}
