
class Solution {
public:
    class Pair{
        public:
        int x = 0,y = 0;
        Pair(int i, int j){
            y = i;
            x = j;
        }
    };

    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<Pair> q;
        int n = board.size();
        if(n == 0)
            return;
        int m = board[0].size();
        if(m == 0)
            return;
        for(int i = 0 ; i < m ; i ++){
            if(board[0][i] == 'O')
                q.push(Pair(0, i));
            if(board[n-1][i] == 'O')
                q.push(Pair(n-1, i));
        }
        for(int i = 0 ; i< n ;i ++){
            if(board[i][0] == 'O')
                q.push(Pair(i, 0));
            if(board[i][m-1] == 'O')
                q.push(Pair(i, m-1));
        }

        Pair p(0, 0);        
        while(!q.empty()){
            p = q.front();
            q.pop();
            board[p.y][p.x] = 'Y';
            if(p.y > 0 && board[p.y-1][p.x] == 'O')
                q.push(Pair(p.y-1, p.x));
            if(p.y < n-1 && board[p.y+1][p.x] == 'O')
                q.push(Pair(p.y+1, p.x));
            if(p.x > 0 && board[p.y][p.x-1] == 'O')
                q.push(Pair(p.y, p.x-1));
            if(p.x < m-1 && board[p.y][p.x+1] == 'O')
                q.push(Pair(p.y, p.x+1));
        }
        
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m  ; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
};
