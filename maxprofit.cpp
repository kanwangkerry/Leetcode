class Solution {
public:
    struct result{
        int max_val;
        int min_val;
        int max_profit;
    };
    struct result find_max(vector<int> &prices, int begin, int end){
        struct result left, right, temp;
        if(end == begin){
            temp.max_profit = 0;
            return temp;
        }
        if(end - begin == 1){
            temp.min_val = prices[begin];
            temp.max_val = prices[begin];
            temp.max_profit = 0;
            return temp;
        }
        left = find_max(prices, begin, (begin+end)/2);
        right = find_max(prices, (begin+end)/2, end);
        int a = right.max_val - left.min_val;
        if(a > left.max_profit && a > right.max_profit) temp.max_profit = a;
        else if(left.max_profit > right.max_profit) temp.max_profit = left.max_profit;
        else temp.max_profit = right.max_profit;
        temp.min_val = (left.min_val < right.min_val)?left.min_val:right.min_val;
        temp.max_val = (left.max_val > right.max_val)?left.max_val:right.max_val;
        return temp;        
    }
    
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return find_max(prices, 0, prices.size()).max_profit;
    }
};
