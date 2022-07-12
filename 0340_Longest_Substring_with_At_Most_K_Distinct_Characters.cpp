class Solution {
public:
    //Time O(N), Space O(k)
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0){
            return 0;
        }
        int longestLen = 0, i = 0, j = 0;
        unordered_map<char, int> hashMap;
        while(j < s.length()){
            if(hashMap.count(s[j]) == 0){
                hashMap[s[j]] = 1;
                while(hashMap.size() > k){
                    if(--hashMap[s[i]] == 0){
                        hashMap.erase(s[i]);
                    }
                    ++i;
                }
            }else{
                ++hashMap[s[j]];
            }
            ++j;
            longestLen = max(longestLen, j-i);
        }
        return longestLen;
    }
};
