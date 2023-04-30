class Solution {
public:
    // vector<vector<int> > memo;
    // int getMaxLen(string& text1, string& text2, size_t i, size_t j){
    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
    //     if(text1[i] == text2[j]){
    //         memo[i][j] = 1+getMaxLen(text1,text2,i+1,j+1);
    //     }else{
    //         memo[i][j] = max(getMaxLen(text1, text2, i+1, j), getMaxLen(text1, text2, i, j+1));
    //     }
    //     return memo[i][j];
    // }
    // // Time O(MN), Space O(MN)
    // int longestCommonSubsequence(string text1, string text2) {
    //     size_t len1 = text1.length(), len2 = text2.length();
    //     memo = vector<vector<int> >(len1+1, vector<int>(len2+1, -1));
    //     for(size_t i = 0; i < text1.length(); ++i){
    //         memo[i][len2] = 0;
    //     } 
    //     for(size_t i = 0; i < text2.length(); ++i){
    //         memo[len1][i] = 0;
    //     }
    //     memo[len1][len2] = 0;
    //     return getMaxLen(text1, text2, 0, 0);
    // }

    // Time O(MN), Space O(MN)
    // int longestCommonSubsequence(string text1, string text2){
    //     int len1 = text1.length(), len2 = text2.length();
    //     int dp[len1+1][len2+1];
    //     memset(dp, 0, sizeof(dp));
    //     for(int i = len1-1; i >= 0; --i){
    //         for(int j = len2-1; j >= 0; --j){
    //             if(text1[i] == text2[j]){
    //                 dp[i][j] = 1 + dp[i+1][j+1];
    //             }else{
    //                 dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }

    // Time O(MN), Space O(min(M,N))
    int longestCommonSubsequence(string text1, string text2){
        if(text1.length() > text2.length()){
            swap(text1, text2);
        }
        int len1 = text1.length(), len2 = text2.length();
        int dp[len1+1];
        memset(dp, 0, sizeof(dp));
        for(int j = len2-1; j >= 0; --j){
            int pre = 0;
            for(int i = len1-1; i >= 0; --i){
                int tmp = dp[i];
                dp[i] = text1[i] == text2[j]? 1+pre : max(dp[i+1], dp[i]);
                pre = tmp;
            }
        }
        return dp[0];
        
    }
};
