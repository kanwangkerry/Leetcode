struct Position {
    int row;
    int col;
};
class Solution {
public:
    inline bool isValid(vector<vector<char> > &board, Position &p) {
        char val = board[p.row][p.col];
        if(val < '1' || val > '9') return false;
        //cout<<val<<"vT";
        
        //1.check row
        vector<char> &brow = board[p.row];
        const int width = brow.size();
        for(int ic = 0; ic < width; ++ ic) {
            if(ic != p.col 
                && brow[ic] != '.' 
                && brow[ic] == val) {
                //cout<<brow[ic]<<"rF";
                return false;
            }
        }
        //cout<<"rT";

        //2.check column
        const int height = board.size();
        for(int ir = 0 ; ir < height; ++ir) {
            if(ir != p.row 
                && board[ir][p.col] != '.' 
                && board[ir][p.col] == val)
                return false;
        }
        
        //3.check 3*3 grid
        const int baseri = p.row / 3 * 3;
        const int baseci = p.col / 3 * 3;
        for(int ir = baseri; ir < baseri + 3; ++ir) {
            for(int ic = baseci; ic < baseci + 3; ++ic) {
                if(ir != p.row && ic != p.col
                    && board[ir][ic] != '.' 
                    && board[ir][ic] == val)
                    return false;
            }
        }
        
        //cout<<"T";
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        static int times = 0;
        //if(times ++ > 0) return;
        
        vector<Position> pts;//empty positions
        int rows = board.size();
        if(0 == rows) return;
        int cols = board[0].size();
        if(0 == cols) return;
        
        //1.found all the empties
        for(int ir = 0 ; ir < rows; ++ir) {
            for(int ic = 0; ic < cols; ++ ic) {
                if(board[ir][ic] == '.') {
                    Position p;
                    p.row = ir;
                    p.col = ic;
                    pts.push_back(p);
                }
            }
        }
        if(pts.size() == 0) return;//no empty cells

        //2.back tracing to fill the empties
        int curi = 0;
        bool forward = true;
        board[pts[curi].row][pts[curi].col] = '1';
        while(curi >= 0) {
            if(curi >= pts.size()) return;
            Position &curPt = pts[curi];
            if(forward) {
                bool valid = isValid(board,curPt);
                if(valid) {
                    ++curi;
                } else {
                    forward = false;
                }
            } else {
                char &c = board[curPt.row][curPt.col];
                if(c == '9') {
                    //no siblings
                    c = '.';
                    --curi;
                } else {
                    c += 1;
                    forward = true;
                }
            }
        }
    }//end function
};
