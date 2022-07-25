class Solution {
public:
    //Time O(N^2logN), Space O(N)
    // int longestRepeatingSubstring(string s) {
    //     int len = s.length();
    //     int left = 0, right = len;
    //     string_view sv = s;
    //     unordered_set<string_view> hashSet;
    //     while(left < right){
    //         int mid = left + ((right-left)>>1) + 1;
    //         bool hasDuplicates = false;
    //         for(int i = 0; i < len-mid+1; ++i){
    //             auto [it, inserted] = hashSet.insert(sv.substr(i, mid));
    //             if(!inserted){
    //                 hasDuplicates = true;
    //                 break;
    //             }
    //         }
    //         if(hasDuplicates){
    //             left = mid;
    //         }else{
    //             right = mid-1;
    //         }
    //         hashSet.clear();
    //     }
    //     return left;
    // }
    
    int N;
    int a = 26;
    long long mod = pow(2,23);
    long long getPower(int a, int b){
        long long res = 1;
        while(b != 0){
            if(b%2){
                res = res*a%mod;
            }
            a = (long long)a*a%mod;
            b >>= 1;
        }
        return res;
    }
    bool search(string& s, int L){
        long long hashVal = 0;
        for(int i = 0; i < L; ++i){
            hashVal = (hashVal*a+(s[i]-'a'))%mod;
        }
        long long firstPower = getPower(a, L-1);
        unordered_set<int> hashSet; 
        hashSet.insert(0);
        for(int i = 1; i < N-L+1; ++i){
            hashVal = ((((hashVal- (s[i-1]-'a')*firstPower)*a)%mod+mod)%mod+(s[i+L-1]-'a'))%mod;
            if(hashSet.count(hashVal)){
                return true;
            }
            hashSet.insert(hashVal);
        }
        return false;
    }
    //Time O(NlogN), Space O(N)
    int longestRepeatingSubstring(string s){
        N = s.length();
        int left = 0, right = N;
        while(left < right){
            int mid = left + ((right-left)>>1) + 1;
            if(search(s, mid)){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        return left;
    }
};
