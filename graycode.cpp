
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> g;
        vector<int> g1;

        g1.push_back(0);
        if(n == 0)
            return g1;
        g1.push_back(1);
        g.push_back(g1);

        for(int i = 1 ; i < n ;i ++){
            vector<int> temp = g[i-1];
            vector<int> revert = temp;
            int m = revert.size();
            for(int j = 0 ; j < m/2; j ++){
                int swap = revert[j];
                revert[j] = revert[m -1 - j];
                revert[m - 1 -j] = swap;
            }
            for(int j = 0 ; j < m ; j++){
                temp.push_back((1 << i) | revert[j]);
            }
            g.push_back(temp);
        }
        return g[n-1];
    }
};
