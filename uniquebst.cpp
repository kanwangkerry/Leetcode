
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *result = new int[n+1];
        result[0] = 1;
        result[1] = 1;
        result[2] = 2;
        for(int i = 3 ; i <= n ; i ++){
            int sum = 0;
            for(int j = 0; j < i ; j++){
                sum += result[j] * result[i -1 -j];
            }
            result[i] = sum;
        }
        return result[n];
    }
};
