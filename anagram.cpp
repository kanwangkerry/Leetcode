
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        map<string, string> ana;
        string temp;
        for(string s:strs){
            temp = s;
            sort(s.begin(), s.end());
            if(ana.count(s)){
                result.push_back(temp);
                if(ana[s] != "TRY"){
                    result.push_back(ana[s]);
                    ana[s] = "TRY";
                }
            }
            else{
                ana[s] = temp;
            }
        }
        return result;
    }
};
