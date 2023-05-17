class Solution {
public:
    // Time O(M^2N^2), Space O(1)
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        while(true){
            bool hasBlank = false;
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    if(board[i][j] == 0){
                        continue;
                    }
                    int a = abs(board[i][j]);
                    if(i > 0 && i < rows-1 && abs(board[i-1][j]) == a && a == abs(board[i+1][j])){
                        board[i-1][j] = board[i][j] = board[i+1][j] = -a;
                        hasBlank = true;
                    }
                    if(j > 0 && j < cols-1 && abs(board[i][j-1]) == a && a == abs(board[i][j+1])){
                        board[i][j-1] = board[i][j] = board[i][j+1] = -a;
                        hasBlank = true;               
                    }
                }
            } 
            if(!hasBlank){
                return board;
            }
            for(size_t i = 0; i < rows; ++i){
                for(size_t j = 0; j < cols; ++j){
                    if(board[i][j] < 0){
                        board[i][j] = 0;
                    }
                }
            } 
            for(int j = 0; j < cols; ++j){
                int k = rows-1;
                for(int i = rows-1; i >= 0; --i){
                    if(board[i][j] > 0){
                        board[k--][j] = board[i][j];
                    }
                }
                while(k != -1){
                    board[k--][j] = 0;
                }
            }

        }

    }
};
