class Solution {
public:
    bool is_safe(vector<vector<char>>& board,int r,int c, char d){
        // For horizontal
        for(int i=0;i<9;i++){
            if(board[r][i]==d){
                return false;
            }
        }
        // For vertical
        for(int i=0;i<9;i++){
            if(board[i][c]==d){
                return false;
            }
        }
        // For smaller grids:
        int sr,sc;
        sr=(r/3)*3;
        sc =(c/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==d){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row, int col){
        if(row==9)return true;
        int nextRow=row;
        int nextCol=col+1;
        if(nextCol==9){
            nextRow=row+1;
            nextCol=0;
        }
        if(board[row][col]!='.'){
            return helper(board,nextRow,nextCol);
        }
        for(char dig='1';dig<='9';dig++){
            if(is_safe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nextRow,nextCol)){
                    return true;                    
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};
