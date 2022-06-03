class Solution {
public:
    // vector<int> memo;
    // int dfs(string &s, int cur){
    //     if(cur == s.length()){
    //         return 1;
    //     }else if(memo[cur] != -1){
    //         return memo[cur];
    //     }else if(s[cur] == '0'){
    //         memo[cur] = 0;
    //         return 0;
    //     }
    //     int res = dfs(s, cur+1);
    //     if(cur+1 < s.length() && (s[cur] < '2' || s[cur] == '2' && s[cur+1] <= '6')){
    //         res += dfs(s, cur+2);
    //     }
    //     memo[cur] = res;
    //     return res;
    // }
    // //Time O(N), Space O(N)
    // int numDecodings(string s) {
    //     memo.resize(s.length(), -1);
    //     return dfs(s, 0);
    // }
    
    //Time O(N), Space O(1)
    int numDecodings(string s){
        int len = s.length();
        int v0 = 1;
        int v1 = s[len-1]=='0'? 0:1;
        for(int i = len-2; i >= 0; --i){
            if(s[i] == '0'){
                v0 = v1;
                v1 = 0;
            }else{
                int v = v1;
                if(s[i] < '2' || s[i] == '2' && s[i+1] <= '6'){
                    v += v0;
                }
                v0 = v1;
                v1 = v;
            }
        }
        return v1;
    }
};
