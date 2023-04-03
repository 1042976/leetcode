class Solution {
public:
    unordered_map<char, int> hashMap;
    int m, n;
    int rows[9], cols[9], subGrids[9];
    pair<int, int> getNextDot(vector<vector<char>>& board, int i, int j){
        for(int nJ = j; nJ < n; ++nJ){
            if(board[i][nJ] == '.'){
                return make_pair(i, nJ);
            }
        }
        for(int nI = i+1; nI < m; ++nI){
            for(int nJ = 0; nJ < n; ++nJ){
                if(board[nI][nJ] == '.'){
                    return make_pair(nI, nJ);
                }
            }
        }
        return make_pair(m, n);
    }
    bool backtrack(vector<vector<char>>& board, int i, int j){
        if(i == m && j == n){
            return true;
        }
        int k = 1;
        char digit = '1';
        while(k <= 256){
            if((rows[i]&k)==0 && (cols[j]&k)==0 && (subGrids[3*(i/3)+j/3]&k)==0){
                rows[i] |= k;
                cols[j] |= k;
                subGrids[3*(i/3)+j/3] |= k;
                board[i][j] = digit;
                auto [nI, nJ] = getNextDot(board, i, j+1);
                if(backtrack(board, nI, nJ)){
                    return true;
                }
                board[i][j] = '.';
                rows[i] -= k;
                cols[j] -= k;
                subGrids[3*(i/3)+j/3] -= k;
            }
            k <<= 1;
            ++digit;
        }
        return false;
    }
    //Time O(N^(N^2)), Space O(N^2), N = 9.
    void solveSudoku(vector<vector<char>>& board) {
        int k = 1;
        for(char i = '1'; i <= '9'; ++i){
            hashMap[i] = k;
            k <<= 1;
        }
        m = board.size();
        n = board[0].size();
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(subGrids, 0, sizeof(subGrids));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    k = hashMap[board[i][j]];
                    rows[i] |= k;
                    cols[j] |= k;
                    subGrids[3*(i/3)+j/3] |= k;                   
                }
            }
        }
        auto [i, j] = getNextDot(board, 0, 0);
        backtrack(board, i, j);      
    }
};
