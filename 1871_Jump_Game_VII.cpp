class Solution {
public:
    //Time O(N), Space O(N)
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.length();
        bool dp[len];
        dp[0] = true;
        for(int i = 1; i < minJump; ++i){
            dp[i] = false;
        }
        int availables = 0;
        for(int i = minJump; i < len; ++i){
            int left = i-maxJump, right = i-minJump;
            availables += dp[right];
            if(left >= 1){
                availables -= dp[left-1];
            }
            dp[i] = availables > 0 && s[i] == '0';
        }
        return dp[len-1]; 
    }
};
