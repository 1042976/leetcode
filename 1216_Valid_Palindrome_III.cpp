class Solution {
public:
    // vector<vector<int> > memo;
    // int dp(string& s, int i, int j){
    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
    //     if(s[i] == s[j]){
    //         memo[i][j] = dp(s, i+1, j-1);
    //     }else{
    //         memo[i][j] = 1+min(dp(s, i+1, j), dp(s, i, j-1));
    //     }
    //     return memo[i][j];
    // }
    // //Time O(N^2), Space O(N^2)
    // bool isValidPalindrome(string s, int k) {
    //     int len = s.length();
    //     memo.resize(len, vector<int>(len, -1));
    //     for(int i = 0; i < len; ++i){
    //         memo[i][i] = 0;
    //     }
    //     for(int i = 0; i < len-1; ++i){
    //         memo[i][i+1] = s[i] == s[i+1]? 0 : 1;
    //     }
    //     return dp(s, 0, len-1) <= k;
    // }
    
    //Time O(N^2), Space O(N^2)
    // bool isValidPalindrome(string s, int k){
    //     int len = s.length();
    //     int dp[len][len];
    //     memset(dp, 0, sizeof(dp));
    //     for(int i = len-2; i >= 0; --i){
    //         for(int j = i+1; j < len; ++j){
    //             if(s[i] == s[j]){
    //                 dp[i][j] = dp[i+1][j-1];
    //             }else{
    //                 dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[0][len-1] <= k;
    // }
    
    //Time O(N^2), Space O(N)
    bool isValidPalindrome(string s, int k){
        int len = s.length();
        int dp[len];
        memset(dp, 0, sizeof(dp));
        for(int i = len-2; i >= 0; --i){
            int prev = 0;
            for(int j = i+1; j < len; ++j){
                int temp = dp[j];
                if(s[i] == s[j]){
                    dp[j] = prev;
                }else{
                    dp[j] = 1 + min(dp[j], dp[j-1]);
                }
                prev = temp;
            }
        }
        return dp[len-1] <= k;
    }
        
};
