class Solution {
public:
    bool checkSame(string& s, string& t, size_t i, size_t j){
        while(i < s.length() && j < t.length()){
            if(s[i] != t[j]){
                return false;
            }
            ++i;
            ++j;
        }
        return i == s.length() && j == t.length();
    }
    // Time O(N), Space O(N).
    bool isOneEditDistance(string s, string t) {
        if(s.length() > t.length()){
            swap(s, t);
        }
        if(s.length()+1 < t.length()){
            return false;
        }
        size_t i = 0;
        while(i < s.length()){
            if(s[i] != t[i]){
                return checkSame(s, t, i, i+1) || checkSame(s, t, ++i, i);        
            }
            ++i;
        }
        return s.length() < t.length();

    }
};
