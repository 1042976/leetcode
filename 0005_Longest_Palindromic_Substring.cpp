class Solution {
public:
    //dynamic programming. T-O(n^2), S-O(n^2)
    // string longestPalindrome(string s) {
    //     int len = s.length();
    //     vector<vector<bool> > dp(len, vector<bool>(len, false));
    //     for(int i = 0; i < len; ++i){
    //         dp[i][i] = true;
    //     }
    //     for(int i = 0; i < len-1; ++i){
    //         dp[i][i+1] = (s[i]==s[i+1]);
    //     }
    //     for(int l = 3; l <= len; ++l){
    //         for(int i = 0; i < len-l+1; ++i){
    //             int j = i+l-1;
    //             dp[i][j] = dp[i+1][j-1]&&s[i]==s[j];
    //         }
    //     }
    //     int maxLen = 1;
    //     int startIdx = 0;
    //     for(int i = 0; i < len-1; ++i){
    //         for(int j = i+maxLen; j < len; ++j){
    //             if(dp[i][j] && j-i+1 > maxLen){
    //                 maxLen = j-i+1;
    //                 startIdx = i;
    //             }
    //         }
    //     }
    //     return s.substr(startIdx, maxLen);
    // }
    
    //T-O(n^2), S-O(1)
//     string longestPalindrome(string s){
//         int maxLen = 0;
//         int startIdx = 0;
//         int len = s.length();
//         for(int i = 0; i < len; ++i){
//             int len1 = expandCenter(s, i, i);
//             int len2 = expandCenter(s, i, i+1);
//             len1 = max(len1, len2);
//             if(len1 > maxLen){
//                 maxLen = len1;
//                 startIdx = i-(len1-1)/2;
//             }
//         }
//         return s.substr(startIdx, maxLen);
//     }
    
//     int expandCenter(string& s, int l, int r){
//         while(l >= 0 && r < s.length() && s[l] == s[r]){
//             --l;
//             ++r;
//         }
//         return r-l-1;
//     }
    //manachar. T-O(n), S-O(n)
    string longestPalindrome(string s){
        int len = 2*s.length()+1;
        vector<int> palindromeRadius(len, 0);
        string str = "|";
        for(const auto &c : s){
            str.push_back(c);
            str.push_back('|');
        }
        int center = 1, radius = 1;
        while(center < len){
            int l = center-radius, r = center+radius;
            while(l >= 0 && r < len && str[l] == str[r]){
                --l;
                ++r;
            }
            radius = r-center-1;
            palindromeRadius[center] = radius;
            int oldCenter = center;
            int oldRadius = radius;
            int rightBoundary = oldCenter+oldRadius;
            ++center;
            radius = 1;
            while(center <= rightBoundary){
                int maxMirroredRadius = rightBoundary-center;
                int mirroredCenter = oldCenter-(center-oldCenter);
                if(palindromeRadius[mirroredCenter] > maxMirroredRadius){
                    palindromeRadius[center] = maxMirroredRadius;
                }else if(palindromeRadius[mirroredCenter] < maxMirroredRadius){
                    palindromeRadius[center] = palindromeRadius[mirroredCenter];
                }else{
                    radius = maxMirroredRadius+1;
                    break;
                }
                ++center;
            }
        }
        center = 0;
        radius = 0;
        for(int i = 0; i < len; ++i){
            if(palindromeRadius[i] > radius){
                center = i;
                radius = palindromeRadius[i];
            }
        }
        string longestPalindrome = str.substr(center-radius, 2*radius+1);
        removeSpecialCharacter(longestPalindrome, '|');
        return longestPalindrome;
    } 
    void removeSpecialCharacter(string& str, char c){
        string str2 = "";
        for(const auto &x : str){
            if(x != c){
                str2.push_back(x);
            }
        }
        str = str2;
    }
};
