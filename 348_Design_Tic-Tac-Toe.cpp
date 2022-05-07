class TicTacToe {
public:
    int size;
    vector<int> rows, columns; 
    int diagonal, antiDiagonal;
    TicTacToe(int n):size(n), rows(n, 0), columns(n, 0), diagonal(0), antiDiagonal(0) {
    }
    
    //T-O(1), S-O(n)
    int move(int row, int col, int player) {
        int a = player == 1 ? 1 : -1;
        int target = player == 1? size : -size;
        rows[row] += a;
        columns[col] += a;
        if(row == col){
            diagonal += a;
        }
        if(row == size-col-1){
            antiDiagonal += a;
        }
        if(rows[row] == target || columns[col] == target || diagonal == target || antiDiagonal == target){
            return player;
        }else{
            return 0;
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
