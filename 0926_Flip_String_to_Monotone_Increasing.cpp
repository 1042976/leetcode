class Solution {
public:
    //Time O(N), Space O(N)
    int minFlipsMonoIncr(string s) {
        int len = s.length();
        int sums[len+1];
        memset(sums, 0, sizeof(sums));
        for(int i = 0; i < len; ++i){
            sums[i+1] = sums[i] + (s[i] == '1'? 1 : 0);
        }
        int minNum = len;
        for(int i = 0; i <= len; ++i){
            minNum = min(minNum, len-i-sums[len]+2*sums[i]);
        }
        return minNum;
    }
};
