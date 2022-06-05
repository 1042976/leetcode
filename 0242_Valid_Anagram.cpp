class Solution {
public:
    //Time O(m+n), Space O(1)
    // bool isAnagram(string s, string t) {
    //     if(s.length() != t.length()){
    //         return false;
    //     }
    //     unordered_map<char, int> hashMap;
    //     for(const auto &c : s){
    //         ++hashMap[c];
    //     }
    //     for(const auto &c : t){
    //         if(hashMap[c] == 0){
    //             return false;
    //         }else{
    //             --hashMap[c];
    //         }
    //     }
    //     return true;
    // }
    
    //Time O(m+n), Space O(1)
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        vector<int> count(26, 0);
        for(const auto &c : s){
            ++count[c-'a'];
        }
        for(const auto &c : t){
            if(count[c-'a'] == 0){
                return false;
            }else{
                --count[c-'a'];
            }
        }
        return true;
    }
};
