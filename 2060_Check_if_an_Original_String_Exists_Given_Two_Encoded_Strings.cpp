class Solution {
public:
    vector<vector<vector<bool> > > memo;
    bool matchDigits(string &s1, string &s2, int i, int j, int balance, int sign){
        int end = j, n = 0;
        while(end+1 < s2.length() && isdigit(s2[end+1])){
            ++end;
        }
        for(int k = j; k <= end; ++k){
            n = n*10 + (s2[k]-'0');
            if(sign == 1){
                if(dfs(s2,s1,k+1,i,balance+n)){
                    return true;
                }  
            }else{
                if(dfs(s1,s2,i,k+1,balance-n)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(string &s1, string &s2, int i, int j, int balance){
        if(i == s1.length() && j == s2.length()){
            return balance == 0;
        }
        if(memo[i][j][balance+999]){
            return false;
        }
        memo[i][j][balance+999] = true;
        if(balance >= 0 && j < s2.length() && isdigit(s2[j])){
            return matchDigits(s1,s2,i,j,balance, -1);
        }else if(balance <= 0 && i < s1.length() && isdigit(s1[i])){
            return matchDigits(s2,s1,j,i,balance, 1);
        }else if(balance > 0 && j < s2.length()){
            return dfs(s1,s2,i,j+1,balance-1);
        }else if(balance < 0 && i < s1.length()){
            return dfs(s1,s2,i+1,j,balance+1);
        }else if(i < s1.length() && j < s2.length() && s1[i] == s2[j]){
            return dfs(s1,s2,i+1,j+1,0);
        }
        return false;
    }
    //Time O(m!n!), Space(mn)
    bool possiblyEquals(string s1, string s2) {
        memo = vector<vector<vector<bool> > >(s1.length()+1,  
                                              vector<vector<bool> >(s2.length()+1, 
                                                                    vector<bool>(1999, false)));
        return dfs(s1, s2, 0, 0, 0);
    }
    

};
