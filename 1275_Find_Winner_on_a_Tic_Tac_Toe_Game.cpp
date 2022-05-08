class Solution {
public:
    //T-O(n), S-O(1)
    string tictactoe(vector<vector<int>>& moves) {
        int available = 9;
        vector<int> rows(3, 0);
        vector<int> cols(3, 0);
        int diagonal = 0, antiDiagonal = 0;
        int currentPlayerValue = 1;
        for(const auto &move : moves){
            int r = move[0], c = move[1];
            --available;
            rows[r] += currentPlayerValue;
            cols[c] += currentPlayerValue;
            if(r == c){
                diagonal += currentPlayerValue;
            }
            if(r == 2-c){
                antiDiagonal += currentPlayerValue;
            }
            if(abs(rows[r]) == 3 || abs(cols[c]) == 3 || abs(diagonal) == 3 || abs(antiDiagonal) == 3){
                return currentPlayerValue == 1? "A" : "B";
            }
            if(available == 0){
                return "Draw";
            }
            currentPlayerValue = -currentPlayerValue;
        }
        return "Pending";
    }
};
