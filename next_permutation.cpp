class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
        int i;
        for(i = len-2 ; i >= 0 ;i --){
            if(num[i] < num[i+1]) break;
        }
        if(i < 0){
            for(i = 0 ; i < len ; i++){
                int temp = num[len-1];
                num.erase(num.end()-1);
                num.insert(num.begin()+i, temp);
            }
        }
        int curr = i;
        for(i = curr+1; i < len ; i++){
            int temp = num[len-1];
            num.erase(num.end()-1);
            num.insert(num.begin()+i, temp);
        }
        for(i = curr+1; i < len; i++){
            if(num[i] > num[curr]){
                int temp = num[i];
                num[i] = num[curr];
                num[curr] = temp;
                break;
            }
        }
        
        
        
    }
};
