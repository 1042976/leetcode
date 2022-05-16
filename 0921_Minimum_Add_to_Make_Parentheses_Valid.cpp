class Solution {
public:
    //Time O(n), Space O(1)
    int minAddToMakeValid(string s) {
        int balance = 0, moves = 0;
        for(const auto &x : s){
            if(x == '('){
                ++balance;
            }else{
                if(balance == 0){
                    ++moves;
                }else{
                    --balance;
                }
            }
        }
        moves += balance;
        return moves;
    }
};
