
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector <vector<int> > > sum(target+1);
        sort(candidates.begin(), candidates.end());
        int nSize = candidates.size();
        for(int i = 1; i  <= target ; i++){
            for(int j = 0 ; j < nSize ;j ++){
                if(i < candidates[j])
                    continue;
                if(candidates[j] == i){
                    vector<int> temp;
                    temp.push_back(j);
                    sum[i].push_back(temp);
                }
                else{
                    int tmp = i - candidates[j];
                    for(int k = 0 ;  k < sum[tmp].size(); k++){
                        if(j > sum[tmp][k].back()){
                            sum[i].push_back(vector<int>(sum[tmp][k]));
                            sum[i].back().push_back(j);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result;
        for(int i = 0 ; i < sum[target].size() ; i ++){
            vector<int> temp;
            for(int j = 0 ; j < sum[target][i].size() ; j++){
                temp.push_back(candidates[sum[target][i][j]]);
            }
            result.push_back(temp);
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(),result.end()),result.end());

        return result;
    }
};
