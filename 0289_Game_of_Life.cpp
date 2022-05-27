class Solution {
public:
    //Time O(N), Space O(1)
    void gameOfLife(vector<vector<int>>& board) {
        int offsets[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int liveN = 0;
                for(const auto &offset : offsets){
                    int nI = i + offset[0];
                    int nJ = j + offset[1];
                    if(nI >= 0 && nI < m && nJ >= 0 && nJ < n && board[nI][nJ]%2){
                        ++liveN;
                    }
                }
                if(board[i][j] == 0){
                    if(liveN == 3){
                        board[i][j] = 2;
                    }
                }else{
                    if(liveN < 2 || liveN > 3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};
