class Solution {
public:
    //Time O(MN), Space O(MN)
    // int minDistance(string word1, string word2) {
    //     int m = word1.length(), n = word2.length();
    //     int dp[m+1][n+1];
    //     for(int i = 0; i <= m; ++i){
    //         dp[i][0] = i;
    //     }
    //     for(int j = 0; j <= n; ++j){
    //         dp[0][j] = j;
    //     }
    //     for(int i = 1; i <= m; ++i){
    //         for(int j = 1; j <= n; ++j){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[i][j] = min(dp[i-1][j-1], min(1+dp[i][j-1], 1+dp[i-1][j]));
    //             }else{
    //                 dp[i][j] = min(1+dp[i-1][j-1], min(1+dp[i][j-1], 1+dp[i-1][j]));
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }
    
    //Time O(MN), Space O(N)
    int minDistance(string word1, string word2){
        int m = word1.length(), n = word2.length();
        int dp[n+1];
        for(int j = 0; j <= n; ++j){
            dp[j] = j;
        }
        for(int i = 1; i <= m; ++i){
            int prev = i-1;
            dp[0] = i;
            for(int j = 1; j <= n; ++j){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]){
                    dp[j] = min(prev, min(1+dp[j-1], 1+dp[j]));
                }else{
                    dp[j] = min(1+prev, min(1+dp[j-1], 1+dp[j]));
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};
