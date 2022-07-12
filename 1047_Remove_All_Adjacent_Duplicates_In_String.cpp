class Solution {
public:
    //Time O(N^2), Space O(1)
    // string removeDuplicates(string s) {
    //     int i = 0;
    //     int len = s.length();
    //     while(i < len-1){
    //         if(s[i] == s[i+1]){
    //             s.erase(i, 2);
    //             len -= 2;
    //             if(--i == -1){
    //                 i = 0;
    //             }
    //         }else{
    //             ++i;
    //         }
    //     }
    //     return s;
    // }
    
    //Time O(N), Space O(1)
    string removeDuplicates(string s){
        string res = "";
        for(const auto &c : s){
            if(!res.empty() && res.back() == c){
                res.pop_back();
            }else{
                res.push_back(c);
            }
        }
        return res;
    }
};
