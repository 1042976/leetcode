class Solution {
public:
    // enum flag{
    //     EMPTY,
    //     TRUE,
    //     FALSE
    // };
    // //T-O(MN). S-O(MN)
    // vector<vector<flag> > memo;
    // bool dp(string& s, string& p, int i, int j){
    //     if(j == p.length()){
    //         return i == s.length();
    //     }
    //     if(memo[i][j] != EMPTY){
    //         return memo[i][j] == TRUE? true : false;
    //     }
    //     bool firstMatch = i < s.length() && (s[i]==p[j] || p[j] == '.');
    //     bool res = false;
    //     if(j+1 < p.length() && p[j+1] == '*'){
    //         res = dp(s, p, i, j+2) || firstMatch && dp(s, p, i+1, j);
    //     }else{
    //         res = firstMatch && dp(s,p,i+1,j+1);
    //     }
    //     memo[i][j] = res? TRUE : FALSE;
    //     return res;
    // }
    // bool isMatch(string s, string p) {
    //     memo = vector<vector<flag> >(s.length()+1, vector<flag>(p.length()+1, EMPTY));
    //     bool res = dp(s, p, 0, 0);
    //     return res;
    // }
    
    //T-O(MN), S-O(MN)
    bool isMatch(string s, string p){
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true;
        for(int i = m; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                bool firstMatch = i < m && (s[i]==p[j] || p[j]=='.');
                if(j+1 < n && p[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || firstMatch && dp[i+1][j]; 
                }else{
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];   
    }
};
