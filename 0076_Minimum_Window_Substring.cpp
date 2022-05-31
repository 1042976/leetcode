class Solution {
public:
    //Time O(M+N), Space O(1)
    // string minWindow(string s, string t) {
    //     unordered_map<char, int> hashMap;
    //     for(const auto &c : t){
    //         ++hashMap[c];
    //     }
    //     int count = 0;
    //     int minLen = INT_MAX, minIdx = -1;
    //     int left = -1, right = -1;
    //     for(int i = 0; i < s.length(); ++i){
    //         if(hashMap.count(s[i])){
    //             if(left == -1){
    //                 left = i;
    //             }
    //             if(--hashMap[s[i]] == 0){
    //                 if(++count == hashMap.size()){
    //                     right = i;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     if(count < hashMap.size()){
    //         return "";
    //     }
    //     while(right < s.length()){
    //         while(left <= right){
    //             if(hashMap.count(s[left]) == 0){
    //                 ++left;
    //             }else{
    //                 if(hashMap[s[left]] < 0){
    //                     ++hashMap[s[left]];
    //                     ++left;
    //                 }else{
    //                     break;
    //                 }
    //             }
    //         }
    //         int curLen = right-left+1;
    //         if(curLen < minLen){
    //             minLen = curLen;
    //             minIdx = left;
    //         }
    //         while(++right < s.length() && s[right] != s[left]){
    //             if(hashMap.count(s[right])){
    //                 --hashMap[s[right]];
    //             }
    //         }
    //         ++left;
    //     }
    //     return s.substr(minIdx, minLen);
    // }
    
    
    //Time O(M+N), Space O(1)
    string minWindow(string s, string t) {
        unordered_map<char, int> hashMap;
        for(const auto &c : t){
            ++hashMap[c];
        }
        int count = 0;
        int minLen = INT_MAX, minIdx = -1;
        int left = 0, right = -1;
        while(right < (int)s.length()){
            if(count < hashMap.size()){
                if(hashMap.count(s[++right])){
                    if(--hashMap[s[right]] == 0){
                        ++count;
                    }
                }   
            }else{
                if(hashMap.count(s[left])){
                    int curLen = right-left+1;
                    if(minLen > curLen){
                        minLen = curLen;
                        minIdx = left;
                    }
                    if(++hashMap[s[left]] > 0){
                        --count;
                    }
                }
                ++left;
            }
        }
        return minLen == INT_MAX? "" : s.substr(minIdx, minLen);
    }
};
