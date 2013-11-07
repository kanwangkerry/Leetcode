
class Solution {
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int **result;
        int n = word1.size();
        int m = word2.size();
        if(n == 0)
            return m;
        if(m == 0)
            return n;
        result = new int*[n+1];
        for(int i = 0 ; i <= n ; i++){
            result[i] = new int[m+1];
        }
        result[0][0] = 0;
        for(int i = 0 ; i <= n ; i++){
            result[i][0] = i;
        }
        for(int j = 0 ; j <= m ; j++){
            result[0][j] = j;
        }
        int min = 0;
        for(int i = 1 ; i <=n ;i++){
            for(int j = 1 ;j <= m ;j++){
                min = n+m;
                if(word1[i-1] == word2[j-1] ){
                    min = result[i-1][j-1];
                }
                else{
                    if(result[i-1][j] + 1 < min)
                        min = result[i-1][j] + 1;
                    if(result[i][j-1] + 1 < min)
                        min = result[i][j-1]+1;
                    if(result[i-1][j-1] + 1 < min)
                        min = result[i-1][j-1] +1;
                }
                result[i][j] = min;
            }
        }
        return result[n][m];
        
    }
};
