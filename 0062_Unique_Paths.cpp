class Solution {
public:
    //Time O(mn), Space O(mn)
    // int uniquePaths(int m, int n) {
    //     int dp[m][n];
    //     for(int i = 0; i < m; ++i){
    //         dp[i][n-1] = 1;
    //     }
    //     for(int j = 0; j < n-1; ++j){
    //         dp[m-1][j] = 1;
    //     }
    //     for(int i = m-2; i >= 0; --i){
    //         for(int j = n-2; j >= 0; --j){
    //            dp[i][j] = dp[i+1][j]+dp[i][j+1];
    //         }
    //     }
    //     return dp[0][0];
    // }
    
    //Time O(mn), Space O(min(m,n))
    int uniquePaths(int m, int n) {
        if(m < n){
            swap(m, n);
        }
        int dp[n];
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
        }
        for(int i = m-2; i >= 0; --i){
            for(int j = n-2; j >= 0; --j){
               dp[j] += dp[j+1];
            }
        }
        return dp[0];
    }
};
