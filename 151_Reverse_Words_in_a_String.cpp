class Solution {
public:
    //T-O(N), S-O(1)
    
    string reverseWords(string s) {
        string res = "";
        int i = 0, j = 0;
        while(i < s.length()){
            while(i < s.length() && s[i] == ' '){
                ++i;
            }
            if(i == s.length()){
                break;
            }
            j = i+1;
            while(j < s.length() && s[j] != ' '){
                ++j;
            }
            reverse(s.begin()+i, s.begin()+j);
            res.append(s, i, j-i);
            res.push_back(' ');
            i = j+1;
        }
        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
