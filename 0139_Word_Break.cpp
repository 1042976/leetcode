class Solution {
public:
    enum STATE{
        WHITE,
        TRUE,
        FALSE
    };
    bool dfs(string& s, int l, unordered_set<string>& hashSet, vector<STATE>& memo){
        if(l == s.length()){
            return true;
        }
        if(memo[l] != WHITE){
            return memo[l] == TRUE;
        }
        string word = "";
        int i = l;
        while(i < s.length()){
            word.push_back(s[i]);
            if(hashSet.find(word) != hashSet.end()){
                bool isValid = dfs(s, i+1, hashSet, memo);
                if(isValid){
                    memo[l] = TRUE;
                    return true;
                }
            }
            ++i;
        }
        memo[l] = FALSE;
        return false;
    }
    //Time O(M^2+N), Space O(M+N)
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<STATE> memo(len, WHITE);
        unordered_set<string> hashSet(wordDict.begin(), wordDict.end()); 
        return dfs(s, 0, hashSet, memo);
    }
//     int dfs(string& s, int i, unordered_set<string>& hashSet, vector<int>& memo){
//         if(i == s.length()){
//             return 1;
//         }
//         if(memo[i] != -1){
//             return memo[i];
//         }
        
//         for(int j = i; j < s.length(); ++j){
//             if(hashSet.find(s.substr(i, j-i+1)) != hashSet.end()){
//                 int val = dfs(s, j+1, hashSet, memo);
//                 if(val == 1){
//                     memo[i] = 1;
//                     return 1;
//                 }
//             }
//         }
//         memo[i] = 0;
//         return 0;
//     }
    
//     //Time O(M^3+N), Space O(M+N)
//     bool wordBreak(string s, vector<string>& wordDict){
//         unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
//         vector<int> memo(s.length(), -1); 
//         return dfs(s, 0, hashSet, memo); 
//     }
    
    //Time O(M^3+N), Space O(M+N)
    // bool wordBreak(string s, vector<string>& wordDict){
    //     unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
    //     vector<bool> memo(s.length(), false);
    //     queue<int> Q;
    //     Q.emplace(0);
    //     while(!Q.empty()){
    //         int idx = Q.front();
    //         Q.pop();
    //         if(idx == s.length()){
    //             return true;
    //         }
    //         if(memo[idx] == true){
    //             continue;
    //         }
    //         memo[idx] = true;
    //         for(int j = idx; j < s.length(); ++j){
    //             if(hashSet.find(s.substr(idx, j-idx+1)) != hashSet.end()){
    //                 Q.emplace(j+1);
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    //Time O(M^3+N), Space O(M+N)
    // bool wordBreak(string s, vector<string>& wordDict){
    //     vector<bool> dp(s.length()+1, false);
    //     dp[0] = true;
    //     unordered_set<string> hashSet(wordDict.begin(), wordDict.end());
    //     for(int i = 1; i <= s.length(); ++i){
    //         for(int j = 0; j < i; ++j){                
    //             if(dp[j] && hashSet.count(s.substr(j, i-j))){
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[s.length()];
    // }
};
