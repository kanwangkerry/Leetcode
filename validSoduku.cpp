public class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean contain[] = new boolean[9];
        int i, j, r, c;
        for(i = 0 ; i < 9 ;i ++){
            for(j = 0 ; j < 9 ; j ++){
                contain[j] = false;
            }
            for(j = 0 ; j < 9 ;j ++){
                if(board[i][j] == '.') continue;
                if(contain[board[i][j]-'1'])
                    return false;
                else contain[board[i][j]-'1'] = true;
            }
            for(j = 0 ; j < 9 ; j ++){
                contain[j] = false;
            }
            for(j = 0 ; j < 9 ;j ++){
                if(board[j][i] == '.') continue;
                if(contain[board[j][i]-'1'])
                    return false;
                else contain[board[j][i]-'1'] = true;
            }
            for(j = 0 ; j < 9 ; j ++){
                contain[j] = false;
            }
            for(j = 0 ; j < 9 ;j ++){
                r = (i%3)*3+j%3;
                c = (i/3)* 3 + j/3; 
                if(board[c][r] == '.') continue;
                if(contain[board[c][r]-'1'])
                    return false;
                else contain[board[c][r] - '1'] = true;
            }
        }
        return true;
    }
}
