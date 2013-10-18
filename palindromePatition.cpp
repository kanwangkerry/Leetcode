
class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       

        int len = s.size();
        bool **isPa = new bool*[len];
        for(int i = 0 ; i < len ; i++){
            isPa[i] = new bool[len];
        }
        for(int i = 0 ; i < len -1;  i++){
            isPa[i][i] = true;
            isPa[i][i+1] = (s[i] == s[i+1]);
        }
        isPa[len-1][len-1] = true;
        for(int l = 2; l < len ; l ++){
            for(int i = 0 ; i < len - l ; i ++){
                isPa[i][i+l] = isPa[i+1][i+l-1] && (s[i] == s[i+l]);
            }
        }
        return partitionHelper(s, isPa);
        
    }
   vector<vector<string>> partitionHelper(string s, bool **isPa){
        vector<vector<string>> result, temp;
         if(s.size() == 0){
            vector<string> v;
            result.push_back(v);
            return result;
        }
       if(s.size() == 1){
            vector<string> v;
            v.push_back(s);
            result.push_back(v);
            return result;
        }
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(isPa[i][s.size()-1]){
                temp = partitionHelper(s.substr(0, i), isPa);
                for(vector<string> v:temp){
                    v.push_back(s.substr(i, s.size()-i));
                    result.push_back(v);
                }
            }
        }
        return result;
   }
};
