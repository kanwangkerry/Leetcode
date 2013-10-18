
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size();
        vector<vector<int> > result;
        vector<vector<int> > temp_result;
        if(len == 1){
            result.push_back(num);
            return result;
        }
        for(int i = 0 ; i < len ; i++){
            vector<int> temp = num;
            temp.erase(temp.begin()+i);
            temp_result = permute(temp);
            for(vector<int> x : temp_result){
                x.push_back(num[i]);
                result.push_back(x);
            }
        }
        return result;
    }
};
