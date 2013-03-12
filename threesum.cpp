class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        int i, j, k;
        vector<vector<int>> result;
        vector<int> temp;
        
        int len = num.size();
        for(i = 0 ; i < len ;i++){
            j = i+1, k = len -1;
            int target = 0-num[i];
            while(j < k){
                if(num[j] + num[k] == target){
                   temp.clear();
                   temp.push_back(num[i]);
                   temp.push_back(num[j]);
                   temp.push_back(num[k]);         
                   result.push_back(temp);
                   while(num[j] == num[j+1]) j++;
                   while(num[k] == num[k-1]) k--;
                   j++, k--;
                }
                else if(num[j] + num[k] < target)
                    j++;
                else if(num[j] + num[k] > target)
                    k--;
                      
            }
            while(num[i] == num[i+1]) i++;
        }
        return result;
        
    }
};
