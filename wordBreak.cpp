
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
           int len = s.size();
        bool **isWord = new bool*[len];
        for(int i = 0 ; i < len ; i++){
            isWord[i] = new bool[len];
        }
        for(int l = 1 ; l <= len ; l++){
            for(int i = 0 ; i <= len - l; i++){
                isWord[i][i+l-1] = false;
                if(dict.count(s.substr(i, l)))
                    isWord[i][i+l-1] = true;
                
                for(int k = 1 ; k < l ; k++){
                    if(isWord[i][i+k-1] && isWord[i+k][i+l-1])
                        isWord[i][i+l-1] = true;
                }
            }
        }
        return isWord[0][len-1];
        
    }
};
