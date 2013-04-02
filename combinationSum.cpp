class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector <vector<int> > > sum(target+1);
        for (int i = 1; i <= target; ++i)
        {
            int nSize = candidates.size();
            for (int j = 0; j < nSize; ++j)
            {
                if (i < candidates[j])
                    continue;
                else if (i == candidates[j])
                {
                    sum[i].push_back(vector<int>());
                    sum[i].back().push_back(candidates[j]);
                    continue;
                }
                else
                {
                    int tmp = i - candidates[j];
                    for (int k = 0; k < sum[tmp].size(); ++k)
                    {
                        if (sum[tmp][k].back() <= candidates[j])
                        {
                            sum[i].push_back(vector<int>(sum[tmp][k]));
                            sum[i].back().push_back(candidates[j]);
                        }
                    }
                }
            }
        }
        return sum[target];
    }
};
