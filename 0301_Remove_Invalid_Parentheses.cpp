class Solution {
public:
    vector<string> arr;
    unordered_set<string> hashSet;
    void backtrack(string &s, int l, int r, int opening, int closing, int balance, string& candidate){
        if(l > r){
            if(opening == 0 && closing == 0 && balance == 0){
                hashSet.insert(candidate);
            }
            return;
        }
        
        if(s[l] == '('){
            candidate.push_back(s[l]);
            backtrack(s, l+1, r, opening, closing, balance+1, candidate);
            candidate.pop_back();
            if(opening > 0){
                backtrack(s, l+1, r, opening-1, closing, balance, candidate);
            }       
        }else if(s[l] == ')'){
            if(balance > 0){
                candidate.push_back(s[l]);
                backtrack(s, l+1, r, opening, closing, balance-1, candidate);
                candidate.pop_back();
            }
            if(closing > 0){
                backtrack(s, l+1, r, opening, closing-1, balance, candidate);
            }
        }else{
           candidate.push_back(s[l]);
           backtrack(s, l+1, r, opening, closing, balance, candidate);
           candidate.pop_back();
        }
    }
    //Time O(2^n), Space O(n^2)
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = s.length()-1;
        string headStr = "", tailStr = "";
        while(l <= r && s[l] != '('){
            if(s[l] != ')'){
                headStr.push_back(s[l]);
            }
            ++l;

        }
        while(r >= l && s[r] != ')'){
            if(s[r] != '('){
                tailStr.push_back(s[r]);
            }
            --r;
        }
        reverse(tailStr.begin(), tailStr.end());
        int opening = 0, closing = 0;
        int i = l, j = r;
        while(i <= j){
            if(s[i] == '('){
                ++opening;
            }else if (s[i] == ')'){
                if(opening > 0){
                    --opening;
                }else{
                    ++closing;
                }
            }
            ++i;
        }
        string candidate = "";
        backtrack(s, l, r, opening, closing, 0, candidate);
        vector<string> arr;
        for(const auto &res : hashSet){
            arr.emplace_back(headStr+res+tailStr);
        }
        return arr;
    }
};
