class Solution {
public:
//     vector<vector<string> > res;
//     vector<vector<bool> > memo; 
//     int len;
    
//     void check(string &s, int i, int j){
//         while(i >= 0 && j < len){
//             if(s[i] == s[j]){
//                 memo[i][j] = true;
//                 --i;
//                 ++j;
//             }else{
//                 break;
//             }
//         }
//     }
//     void backtrack(string &s, int cur, vector<string>& arr){\
//         if(cur == len){
//             res.emplace_back(arr);
//             return;
//         }
//         for(int end = cur; end < len; ++ end){
//             if(memo[cur][end]){
//                 arr.emplace_back(s.substr(cur, end-cur+1));
//                 backtrack(s, end+1, arr);
//                 arr.pop_back();
//             }
//         }
//     }
//     //Time O(n* 2^n ), Space O(n^2)
//     vector<vector<string>> partition(string s) {
//         len = s.length();
//         memo.resize(len, vector<bool>(len, false));
//         for(int i = 0; i < len; ++i){
//             check(s, i, i);
//             check(s, i-1, i);
//         }
//         vector<string> arr;
//         backtrack(s, 0, arr);
//         return res;
//     }
    
    vector<vector<string> > res;
    vector<vector<bool> > memo; 
    int len;
    
    bool isPalindromw(string &s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                ++i;
                --j;
            }else{
                return false;
            }
        }
        return true;
    }
    void backtrack(string &s, int cur, vector<string>& arr){\
        if(cur == len){
            res.emplace_back(arr);
            return;
        }
        for(int end = cur; end < len; ++ end){
            if(s[cur] == s[end] && (end-cur <= 1 || memo[cur+1][end-1])){
                memo[cur][end] = true;
                arr.emplace_back(s.substr(cur, end-cur+1));
                backtrack(s, end+1, arr);
                arr.pop_back();
            }
        }
    }
    //Time O(n* 2^n ), Space O(n^2)
    vector<vector<string>> partition(string s) {
        len = s.length();
        memo.resize(len, vector<bool>(len, false));
        vector<string> arr;
        backtrack(s, 0, arr);
        return res;
    }
};
