class Solution {
public:
    vector<string> res;
    void dfs(string str, int opening, int closing){
        if(opening == 0 && closing == 0){
            res.emplace_back(str);
            return;
        }
        if(opening > 0){
            dfs(str+"(", opening-1, closing);
        }
        if(opening < closing){
            dfs(str+")", opening, closing-1);
        }
    }
    
    //Time O(mn), Space O(n), m = (2n n)-(2n-1 n)-(2n-3 n-1)-...-(1 0).
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};
