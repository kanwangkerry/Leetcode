
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        return getSubsets(S, S.size()-1);
    }
    
    vector<vector<int>> getSubsets(vector<int> &s, int begin){
        vector<vector<int>> result, subresult;
        vector<int> *subset;
        vector<int> temp;
        if(begin == 0){
            subset = new vector<int>();
            result.push_back(*subset);
            subset = new vector<int>();
            subset->push_back(s[begin]);
            result.push_back(*subset);
            return result;
        }
        subresult = getSubsets(s, begin - 1);
        for(vector<int> t:subresult){
            result.push_back(t);
            t.push_back(s[begin]);
            result.push_back(t);
        }
        return result;
    }
};
