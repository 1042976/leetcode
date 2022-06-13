class Solution {
public:
    //Time O(N), Space O(1)
    // long long appealSum(string s) {
    //     long long res = 0;
    //     long long a = 0;
    //     vector<int> prev(26, -1);
    //     for(int i = 0; i < s.length(); ++i){
    //         a += i-prev[s[i]-'a'];
    //         res += a;
    //         prev[s[i]-'a'] = i;
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    long long appealSum(string s){
        vector<int> prev(26, -1);
        long long total = 0;
        int len = s.length();
        for(int i = 0; i < s.length(); ++i){
            total += (i-prev[s[i]-'a'])*(len-i);
            prev[s[i]-'a'] = i;
        }
        return total;
    }
};
