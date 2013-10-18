

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        return getSubsets(S, S.size()-1);
    }
    
    vector<vector<int>> getSubsets(vector<int> &s, int begin){
        vector<vector<int>> subresult;
        set<vector<int>> result1;
        vector<int> *subset;
        vector<int> temp;
        if(begin == 0){
            vector<vector<int>> result;
            subset = new vector<int>();
            result.push_back(*subset);
            subset = new vector<int>();
            subset->push_back(s[begin]);
            result.push_back(*subset);
            return result;
        }
        subresult = getSubsets(s, begin - 1);
        for(vector<int> t:subresult){
            result1.insert(t);
            t.push_back(s[begin]);
            result1.insert(t);
        }
        vector<vector<int>> result(result1.begin(), result1.end());
        return result;
    }
};
