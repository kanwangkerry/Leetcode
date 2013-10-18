
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        int len = num.size();
        int min_diff = abs(num[0] + num[1] + num[2] - target);
        int min_result = num[0] + num[1] + num[2];
        for(int i = 0 ; i < len ; i++){
            int t_target = target - num[i];
            int j = i+1, k = len -1;
            while(j < k){
                if(min_diff > abs(num[i] + num[j] + num[k] - target)){
                    min_diff = abs(num[i] + num[j] + num[k] - target);
                    min_result = num[i] + num[j] + num[k];
                }
                if(num[j] + num[k] < t_target){
                    j++;
                }
                else if(num[j] + num[k] > t_target){
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return min_result;
    }
};
