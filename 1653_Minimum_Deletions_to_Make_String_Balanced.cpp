class Solution {
public:
    //T-O(n), S-O(n)
    // int minimumDeletions(string s) {
    //     int len = s.length();
    //     vector<int> dp(len+1, 0);
    //     int countB = 0;
    //     for(int i = 0; i < len; ++i){
    //         if(s[i] == 'b'){
    //             dp[i+1] = dp[i];
    //             ++countB;
    //         }else{
    //             dp[i+1] = min(dp[i]+1, countB);
    //         }
    //     }
    //     return dp[len];
    // }
    //T-O(n), S-O(1)
    int minimumDeletions(string s){
        int countB = 0;
        int res = 0;
        for(const auto &c : s){
            if(c == 'b'){
                ++countB;
            }else{
                if(countB > 0){
                    --countB;
                    ++res;
                }
            }
        }
        return res;
    }
};
