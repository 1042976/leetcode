class Solution {
public:
    int update(string& s, int i, int sign){
        while(i >= 0 && i < s.length()){
            if(isdigit(s[i]) || isalpha(s[i])){
                return i;
            }
            i += sign;
        }
        return i;
    }
    //Time O(n), Space O(1)
    bool isPalindrome(string s) {
        int i = update(s, 0, 1);
        int j = update(s, s.length()-1, -1);
        while(i < j){
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i = update(s, i+1, 1);
                j = update(s, j-1, -1);
            }
        }
        return true;
    }
};
