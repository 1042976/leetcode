class Solution {
public:
    unordered_map<char, int> hashMap;
    //Time O(1), Space O(1). bitmasking
    bool isValidSudoku(vector<vector<char>>& board) {
        //create mappings
        int k = 1;
        for(char c = '1'; c <= '9'; ++c){
            hashMap[c] = k;
            k <<= 1;
        }
        
        //init arrs
        vector<int> rows(9, 1023);
        vector<int> columns(9, 1023);
        vector<int> subBoxes(9, 1023);
        
        //validate
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                int digit = hashMap[c];
                int k = 3*(i/3)+j/3;
                if(rows[i]&digit && columns[j]&digit && subBoxes[k]&digit){
                    rows[i] -= digit;
                    columns[j] -= digit;
                    subBoxes[k] -= digit;
                }else{
                   return false;
                }

            }
        }
        return true;
    }
};
