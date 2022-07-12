class Solution {
public:
    // int longest = 0;
    // void dfs(string &s, int l, int r, int k){
    //     if(r < l){
    //         return;
    //     }
    //     int frequency[26];
    //     memset(frequency, 0, sizeof(frequency));
    //     for(int i = l; i <= r; ++i){
    //         ++frequency[s[i]-'a'];
    //     }
    //     bool isValid = true;
    //     int i = l, j = l;
    //     while(j <= r){
    //         if(frequency[s[j]-'a'] < k){
    //             isValid = false;
    //             dfs(s, i, j-1, k);
    //             i = j+1;
    //         }  
    //         ++j;
    //     }
    //     if(isValid){
    //         longest = max(longest, r-l+1);
    //         return;
    //     }
    //     if(frequency[s[r]-'a'] >= k){
    //         dfs(s, i, r, k);
    //     }
    // }
    // //Time O(N), Space O(1)
    // int longestSubstring(string s, int k) {
    //     dfs(s, 0, s.length()-1, k);
    //     return longest;
    // }
    
    //sliding window. 
    int countUChars(string &s){
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(const auto &c : s){
            ++arr[c-'a'];
        }
        int count = 0;
        for(int i = 0; i < 26; ++i){
            if(arr[i] > 0){
                ++count;
            }
        }
        return count;
    }
    //Time O(N), Space O(1)
    int longestSubstring(string s, int k){
        int totalUChars = countUChars(s);
        int longestLen = 0;
        for(int numOfUChars = 1; numOfUChars <= totalUChars; ++numOfUChars){
            int left = -1, right = -1;
            int arr[26];
            int m = 0, n = 0;
            memset(arr, 0, sizeof(arr));
            while(right < (int)s.length()){
                if(m <= numOfUChars){
                    if(++right == s.length()){
                        break;
                    }
                    int idx = s[right]-'a';
                    if(arr[idx] == 0){
                        ++m;
                    }
                    if(++arr[idx] == k){
                        ++n;
                    }
                }else{
                    ++left;
                    int idx = s[left]-'a';
                    if(arr[idx] == k){
                        --n;
                    }
                    if(--arr[idx] == 0){
                        --m;
                    }
                }
                if(m == n){
                    longestLen = max(longestLen, right-left);
                }                
            }
        }
        return longestLen;
    }
};
