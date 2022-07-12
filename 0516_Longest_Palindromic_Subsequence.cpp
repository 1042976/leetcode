class Solution {
public:
    //Top down.
    // vector<vector<int> > memo;
    // int dp(string &s, int l, int r){
    //     if(l > r){
    //         return 0;
    //     }
    //     if(memo[l][r] != -1){
    //         return memo[l][r];
    //     }
    //     if(s[l] == s[r]){
    //         memo[l][r] = 2+dp(s, l+1, r-1);
    //     }else{
    //         memo[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    //     }
    //     return memo[l][r];
    // }
    // //Time O(N^2), Space O(N^2)
    // int longestPalindromeSubseq(string s){
    //     int N = s.length();
    //     memo.resize(N, vector<int>(N, -1));
    //     for(int i = 0; i < N; ++i){
    //         memo[i][i] = 1;
    //     }
    //     return dp(s, 0, N-1);
    // }
    //bottom up. Time O(N^2), Space O(N^2)
    // int longestPalindromeSubseq(string s) {
    //     int N = s.length();
    //     int dp[N][N];
    //     for(int i = 0; i < N; ++i){
    //         dp[i][i] = 1;
    //     }
    //     for(int i = 0; i < N-1; ++i){
    //         dp[i][i+1] = s[i] == s[i+1]? 2 : 1;
    //     }
    //     for(int len = 2; len < N; ++len){
    //         for(int i = 0; i+len < N; ++i){
    //             int j = i+len;
    //             if(s[i] == s[j]){
    //                 dp[i][j] = dp[i+1][j-1]+2;
    //             }else{
    //                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[0][N-1];
    // }
    
    //bottom. Time O(N^2), Space O(N^2)
    // int longestPalindromeSubseq(string s) {
    //     int N = s.length();
    //     int dp[N][N];
    //     memset(dp, 0, sizeof(dp));
    //     for(int i = 0; i < N; ++i){
    //         dp[i][i] = 1;
    //     }
    //     for(int i = N-2; i >= 0; --i){
    //         for(int j = i+1; j < N; ++j){
    //             if(s[i] == s[j]){
    //                 dp[i][j] = dp[i+1][j-1]+2;
    //             }else{
    //                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[0][N-1];
    // }
    
    //bottom up. Time O(N^2), Space O(N)
    int longestPalindromeSubseq(string s){
        int N = s.length();
        int dp[N];
        for(int i = 0; i < N; ++i){
            dp[i] = 1;
        }
        for(int i = N-2; i >= 0; --i){
            int prev = 0;
            for(int j = i+1; j < N; ++j){
                int temp = dp[j];
                if(s[i] == s[j]){
                    dp[j] = prev+2;
                }else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = temp;
            }
        }
        return dp[N-1];
    }
};
