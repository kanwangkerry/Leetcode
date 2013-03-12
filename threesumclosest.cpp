class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        int min_diff = abs(num[0]+ num[1]+num[2] -target);
        int result = num[0]+num[1]+num[2];
        sort(num.begin(), num.end());
        for(i = 0 ; i < num.size(); i++){
            for(j = i+1 ; j< num.size(); j++){
                int k = target - num[i] -num[j];
                int index =upper_bound(num.begin()+j+1, num.end(), k) - num.begin();
                int temp_diff, temp_result;
                if(index == num.size() && index == j+1){
                    continue;
                }
                else if(index == num.size()){
                    temp_diff = abs(num[index-1] -k);
                    if(min_diff > temp_diff){
                        min_diff = temp_diff;
                        result = num[index-1]+num[i]+num[j];
                    }
                }
                else if(index == j+1){
                    temp_diff = abs(num[index] -k);
                    if(min_diff > temp_diff){
                        min_diff = temp_diff;
                        result = num[index]+num[i]+num[j];
                    }
                }
                else{
                    temp_diff = abs(num[index] -k);
                    temp_result = num[index] + num[i]+num[j];
                    if(temp_diff > abs(num[index-1] -k)){
                        temp_diff = abs(num[index-1]-k);
                        temp_result = num[index - 1] + num[i]+num[j];
                    }
                    if(min_diff > temp_diff){
                        min_diff = temp_diff;
                        result = temp_result;
                    }
                    
                    
                }
            }
        }
        return result;
        
    }
};
