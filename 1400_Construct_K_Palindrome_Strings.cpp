class Solution {
public:
    //Time O(N), Space O(1)
    // bool canConstruct(string s, int k) {
    //     int arr[26];
    //     int odd = 0;
    //     memset(arr, 0,  sizeof(arr));
    //     for(const auto &x : s){
    //         ++arr[x-'a'];
    //     }
    //     for(int i = 0; i < 26; ++i){
    //         if(arr[i]%2){
    //             ++odd;   
    //         }
    //     }
    //     return odd == k || odd < k && s.length() >= k;
    // }
    
    //Time O(N), Space O(1)
    bool canConstruct(string s, int k){
        bitset<26> odd(0);
        for(const auto &x : s){
            odd.flip(x-'a');
        }
        return odd.count() == k || odd.count() < k && s.length() >= k;
    }
};
