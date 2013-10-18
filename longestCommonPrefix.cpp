
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int l = strs.size();
        int i = 0;
        string prefix = "";
        if(l == 0)
            return "";
        int len = strs[0].size();
        for(int i = 0 ; i < len ; i++){
            char x = strs[0][i];
            for(int j = 1 ; j < l ; j ++){
                if(strs[j][i] != x){
                    return prefix;
                }
            }
            prefix.push_back(x);
        }
        return prefix;
    }
};
