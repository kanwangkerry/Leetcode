
public class Solution {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = prices.length;
        if(n == 0)
            return 0;
        int max = 0, preMax = prices[0], currentMin = prices[0];
        int tempD;
        int sum = 0;
        for(int i = 1 ;  i < n ; i++){
            if(prices[i] >= preMax){
                tempD = prices[i] - currentMin;
                preMax = prices[i];
                if(max < tempD)
                    max = tempD;
            }
            else{
                sum += max;
                max = 0;
                currentMin = prices[i];
                preMax = prices[i];
            }
            
        }
        sum += max;
        return sum;
    }
}
