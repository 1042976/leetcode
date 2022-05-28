class Solution {
public:

    //top-down dp.
//     int dp(vector<int>& coins, int amount, int memo[]){
//         if(amount == 0){
//             return 0;
//         }
        
//         if(memo[amount-1] != 0){
//             return memo[amount-1];
//         }
//         int res = INT_MAX;
//         for(const auto &coin : coins){
//             if(coin <= amount){
//                 int step = dp(coins, amount-coin, memo);
//                 if(step == -1){
//                     continue;
//                 }
//                 res = min(step+1, res);
//             }
//         }
//         memo[amount-1] = res == INT_MAX? -1 : res;
//         return memo[amount-1];
//     }
//     //Time O(M*N), Space O(N)
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0){
//             return 0;
//         }
//         int memo[amount];
//         for(int i = 0; i < amount; ++i){
//             memo[i] = 0;
//         }
//         int res = dp(coins, amount, memo);
//         return memo[amount-1];
//     }
    
    //Time O(MN), Space O(N)
    int coinChange(vector<int>& coins, int amount){
        int dp[amount+1];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            dp[i] = INT_MAX;
            for(const auto &coin : coins){
                if(i >= coin && dp[i-coin] != -1){
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }               
            if(dp[i] == INT_MAX){
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
};
