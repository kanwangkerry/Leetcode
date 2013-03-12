class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result = "";
        int len = strs.size();
        int index = 0, i;
        if(len == 0) return result;
        while(1){
            for(i = 0 ; i < len; i++){
                if(strs[i].find(result) != 0) break;
            }
            if(i != len ){
                index --;
                break;
            }
            else if(index == strs[0].size()){
                break;
            }
            else 
                result.push_back(strs[0][index++]);
        }
        return result.substr(0, index);
    }
};
