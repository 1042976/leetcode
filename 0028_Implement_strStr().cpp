class Solution {
public:
    //Time O(NM), Space O(1)
    // int strStr(string haystack, string needle) {
    //     if(needle.empty()){
    //         return 0;
    //     }
    //     int lenH = haystack.length(), lenN = needle.length();
    //     int i = 0;
    //     while(i <= lenH-lenN){
    //         if(haystack[i] == needle[0]){
    //             bool isMatch = true;
    //             for(int j = 1; j < lenN; ++j){
    //                 if(haystack[i+j] != needle[j]){
    //                     isMatch = false;
    //                     break;
    //                 }
    //             }
    //             if(isMatch){
    //                 return i;
    //             }
    //         }
    //         ++i;
    //     }
    //     return -1;
    // }
    
    //KMP.
    void computeLPS(string &needle, int lps[], int m){
        lps[0] = 0;
        int i = 1, j = 0;
        while(i < m){
            if(needle[i] == needle[j]){
                lps[i++] = ++j;
            }else{
                if(j != 0){
                    j = lps[j-1];
                }else{
                    lps[i++] = 0;
                }
            }
        }
    }
    //Time O(N), Space O(M)
    int strStr(string haystack, string needle){
        if(needle.empty()){
            return 0;
        }
        int n = haystack.length(), m = needle.length();
        int lps[m];
        computeLPS(needle, lps, m);
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                if(j == m-1){
                    return i-j;
                }
                ++i;
                ++j;
            }else{
                if(j != 0){
                    j = lps[j-1];
                }else{
                    ++i;
                }
            } 
        }
        return -1;
    }
};
