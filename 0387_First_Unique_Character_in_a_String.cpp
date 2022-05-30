class Solution {
public:
    //Time O(N), Space O(1)
    int firstUniqChar(string s) {
        unordered_map<char, int> hashMap;
        for(const auto &c : s){
            ++hashMap[c];
        }
        for(int i = 0; i < s.length(); ++i){
            if(hashMap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
