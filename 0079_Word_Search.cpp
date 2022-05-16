class Solution {
public:
    //T-O(mn*3^l), S-O(l).
    vector<vector<char>> board;
    int M, N;
    bool exist(vector<vector<char>>& board, string word){
        this->board = board;
        this->M = board.size();
        this->N = board[0].size();
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N; ++j){
                if(backtrack(word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrack(string& word, int cur, int row, int col){
        if(cur == word.length()){
            return true;
        }
        if(row < 0 || col < 0 || row == M || col == N || word[cur] != board[row][col]){
            return false;
        }
        board[row][col] = '0';
        ++cur;
        bool res = backtrack(word, cur, row-1, col) || backtrack(word, cur, row, col-1) ||
            backtrack(word, cur, row+1, col) || backtrack(word, cur, row, col+1);
        board[row][col] = word[cur-1];
        return res;
    }
};
