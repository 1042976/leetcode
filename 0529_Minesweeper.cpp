class Solution {
public:
    // int m, n;
    // int offsets[8][2] {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    // void dfs(vector<vector<char>>& board, vector<int>& target){
    //     const int& row = target[0], &col = target[1];
    //     if(board[row][col] == 'M'){
    //         return;
    //     }
    //     int numOfMines = 0;
    //     vector<vector<int> > adj;
    //     for(int i = 0; i < 8; ++i){
    //         int newRow = row + offsets[i][0];
    //         int newCol = col + offsets[i][1];
    //         if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
    //             const char& c = board[newRow][newCol];
    //             if(c == 'E'){
    //                 adj.emplace_back(vector<int>{newRow, newCol});
    //             }
    //             numOfMines += c == 'M';
    //         }
    //     }
    //     board[row][col] = numOfMines == 0? 'B' : numOfMines+'0';
    //     if(board[row][col] == 'B'){
    //         for(auto &next : adj){
    //             dfs(board, next);
    //         }          
    //     }
    // }
    //Time O(MN), Space O(MN), M is the number of rows while N is the number of columns
    // vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    //     const int& row = click[0], &col = click[1];
    //     if(board[row][col] == 'M'){
    //         board[row][col] = 'X';
    //         return board;
    //     }
    //     m = board.size();
    //     n = board[0].size();
    //     dfs(board, click);
    //     return board;
    // }
       
    //Time O(MN), Space O(min(M, N));
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click){
        int row = click[0], col = click[1];
        if(board[row][col] == 'M'){
            board[row][col] = 'X';
            return board;
        }
        int m = board.size(), n = board[0].size();
        int offsets[8][2] {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}}; 
        queue<pair<int, int> > Q;
        Q.emplace(make_pair(row, col));
        while(!Q.empty()){
            row = Q.front().first;
            col = Q.front().second;
            Q.pop();
            int numOfMines = 0;
            vector<pair<int, int> > adj;
            for(int i = 0; i < 8; ++i){
                int newRow = row + offsets[i][0];
                int newCol = col + offsets[i][1];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    char& c = board[newRow][newCol];
                    if(c == 'E'){
                        adj.emplace_back(make_pair(newRow, newCol));
                    }
                    if(c == 'M'){
                        ++numOfMines;
                    }
                }
            }
            board[row][col] = numOfMines == 0? 'B' : numOfMines + '0';
            if(board[row][col] == 'B'){
                for(const auto& next : adj){
                    board[next.first][next.second] = 'V';
                    Q.emplace(next);
                }
            }
        }
        return board;
    }
};
