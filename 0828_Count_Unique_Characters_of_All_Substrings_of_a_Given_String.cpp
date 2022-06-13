class Solution {
public:
    //Time O(N), Space O(1)
    int uniqueLetterString(string s) {
        int total = 0;
        int prev[26][2];
        memset(prev, -1, sizeof(prev[0][0])*52);
        int len = s.length();
        for(int k = 0; k < len; ++k){
            int idx = s[k]-'A';
            int i = prev[idx][0], j = prev[idx][1];
            total += (j-i)*(k-j);
            prev[idx][0] = j;
            prev[idx][1] = k;
        }
        for(int idx = 0; idx < 26; ++idx){
            int i = prev[idx][0], j = prev[idx][1];
            total += (j-i)*(len-j);
        }
        return total;
    }
};
