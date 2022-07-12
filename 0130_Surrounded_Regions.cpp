class Solution {
public:
    int m, n;
    // void bfs(vector<vector<char> >& board, int i, int j){
    //     queue<pair<int, int> > Q;
    //     Q.emplace(make_pair(i, j));
    //     while(!Q.empty()){
    //         auto [row, col] = Q.front();
    //         Q.pop();
    //         if(board[row][col] != 'O'){
    //             continue;
    //         }
    //         board[row][col] = 'T';
    //         if(row < m-1){
    //             Q.emplace(make_pair(row+1, col));
    //         }
    //         if(col < n-1){
    //             Q.emplace(make_pair(row, col+1));
    //         }
    //         if(row > 0){
    //             Q.emplace(make_pair(row-1, col));
    //         }
    //         if(col > 0){
    //             Q.emplace(make_pair(row, col-1));
    //         }
    //     }
    // }
    // //Time O(N), Space O(N)
    // void solve(vector<vector<char>>& board) {
    //     m = board.size();
    //     n = board[0].size();
    //     int rows[2] = {0, m-1};
    //     for(int i = 0; i < 2; ++i){
    //         int row = rows[i];
    //         for(int col = 0; col < n; ++col){
    //             if(board[row][col] == 'O'){
    //                 bfs(board, row, col);
    //             }
    //         }
    //     }
    //     int cols[2] = {0, n-1};
    //     for(int i = 0; i < 2; ++i){
    //         int col = cols[i];
    //         for(int row = 1; row < m-1; ++ row){
    //             if(board[row][col] == 'O'){
    //                 bfs(board, row, col);
    //             }
    //         }
    //     }
    //     for(int row = 0; row < m; ++row){
    //         for(int col = 0; col < n; ++col){
    //             if(board[row][col] == 'O'){
    //                 board[row][col] = 'X';
    //             }else if(board[row][col] == 'T'){
    //                 board[row][col] = 'O';
    //             }
    //         }
    //     }
    // }
    
    void dfs(vector<vector<char> >& board, int row, int col){
        if(board[row][col] != 'O'){
            return;
        }
        board[row][col] = 'T';
        if(row < m-1){
            dfs(board, row+1, col);
        }
        if(row > 0){
            dfs(board, row-1, col);
        }
        if(col < n-1){
            dfs(board, row, col+1);
        }
        if(col > 0){
            dfs(board, row, col-1);
        }
    }
    //Time O(N), Space O(N)
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        int rows[2] = {0, m-1};
        for(int i = 0; i < 2; ++i){
            int row = rows[i];
            for(int col = 0; col < n; ++col){
                if(board[row][col] == 'O'){
                   dfs(board, row, col);
                }
            }
        }
        int cols[2] = {0, n-1};
        for(int i = 0; i < 2; ++i){
            int col = cols[i];
            for(int row = 1; row < m-1; ++ row){
                if(board[row][col] == 'O'){
                    dfs(board, row, col);
                }
            }
        }
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(board[row][col] == 'O'){
                    board[row][col] = 'X';
                }else if(board[row][col] == 'T'){
                    board[row][col] = 'O';
                }
            }
        }
    }
};
