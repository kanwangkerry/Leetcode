
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int i, j, k, l;
        vector<vector<int> >result;
        
        sort(num.begin(), num.end());
        for(i = 0 ; i < num.size(); i++){
            if(num[i] == num[i-1]) continue;
            for(j = i+1; j< num.size(); j++){
                if(num[j] == num[j-1] && j!=i+1) continue;
                k = j + 1, l = num.size()-1;
                while(k < l){
                    if(k != j+1 && num[k] == num[k-1]){
                        k++;
                        continue;
                    }
                    if( l != num.size()-1 && num[l] == num[l+1]){
                        l--;
                        continue;
                    }
                    if(num[k]+ num[l] < target - num[i] - num[j]) k++;
                    else if(num[k]+num[l] > target-num[i]-num[j]) l--;
                    else{
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[k]);
                        temp.push_back(num[l]);
                        result.push_back(temp);
                        k++, l--;
                    }
                }
               
            }
        }
        return result;
        
    }
};
