
struct Pair{
    int i, j;
    Pair(int i_i, int i_j){ i = i_i, j = i_j;}
};
class Solution {
    
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = board.size();
        if(n ==0 )
            return false;
        int m = board[0].size();
        bool **visited;
        visited = new bool*[n];
        
        for(int i = 0 ; i < n ; i++)
            visited[i] = new bool[m];
            
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j  < m; j++){
                if(board[i][j] == word[0]){
                   
                    if(searchWord(board, word, 1, m ,n, i, j ,visited))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool searchWord(vector<vector<char> > &board, string word, int curr, int m, int n, int i, int j, bool **visited){
        if(word.size() == curr)
            return true;
        bool result  = false;
        visited[i][j] = true;
        if(i > 0 && board[i-1][j] == word[curr] && visited[i-1, j] == false){
            result = searchWord(board, word, curr+1, m, n , i-1, j, visited);
            if(result == true)
                return true;
        }
        if(i < n-1 && board[i+1][j] == word[curr] && visited[i+1, j] == false){
            result = searchWord(board, word, curr+1, m, n , i+1, j, visited);
            if(result == true)
                return true;
        }
        if(j > 0 && board[i][j-1] == word[curr] && visited[i, j-1] == false){
            result = searchWord(board, word, curr+1, m, n , i, j-1, visited);
            if(result == true)
                return true;
        }
        if(j < m-1 && board[i][j+1] == word[curr] && visited[i, j+1] == false){
            result = searchWord(board, word, curr+1, m, n , i, j+1, visited);
            if(result == true)
                return true;
        }
        visited[i][j] = false;
        return false;
    }
  
};
