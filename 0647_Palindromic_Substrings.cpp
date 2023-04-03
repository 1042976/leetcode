class Solution {
public:
    int countPalindrome(string &s, int i, int j){
        int res = 0;
        while(i >= 0 & j < s.length()){
            if(s[i] != s[j]){
                break;
            }
            ++res;
            --i;
            ++j;
        }
        return res;
    }
    //Time O(N^2), Space O(1)
    int countSubstrings(string s) {
        int res = s.length();
        for(int i = 0; i < s.length()-1; ++i){
            res += countPalindrome(s, i-1, i+1);
            res += countPalindrome(s, i, i+1);
        }
        return res;
    }
};
