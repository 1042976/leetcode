class Solution {
public:
    long long mod = 1e+9+7;
    int a = 26;
    int N;
    long long getPower(long long a, int b){
        long long res = 1;
        while(b != 0){
            if(b%2){
                res = res*a%mod;
            }
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    int search(string& s, int L){
        unordered_map<int, vector<int> > hashMap;
        long long hashVal = 0;
        for(int i = 0; i < L; ++i){
            hashVal = ((hashVal*a) + (s[i]-'a'))%mod;
        }
        long long aExp = getPower(a, L-1);
        hashMap[hashVal].emplace_back(0);
        for(int i = 1; i < N-L+1; ++i){
            hashVal = ((hashVal-(s[i-1]-'a')*aExp)*a%mod+mod)%mod + (s[i+L-1]-'a');
            hashVal %= mod;
            if(hashMap.count(hashVal)){
                for(const auto &j : hashMap[hashVal]){
                    if(s.compare(i, L, s, j, L) == 0){
                        return j;
                    }
                }
            }
            hashMap[hashVal].emplace_back(i);
        }
        return -1;
    }
    //Time O(NlogN), Space O(N)
    string longestDupSubstring(string s) {
        N = s.length();
        int left = 1, right = N;
        while(left < right){
            int mid = left + ((right-left)>>1)+1;
            if(search(s, mid) != -1){
                left = mid;
            }else{
                right = mid-1;
            }
        }
        int startPos = search(s, left);
        return startPos == -1? "" : s.substr(startPos, left);
    }
    
    //Time O(LNlogN), Space O(N)
    // string longestDupSubstring(string s){
    //     int len = s.length();
    //     int left = 1, right = len-1;
    //     string_view sv = s;
    //     string_view longest;
    //     unordered_set<string_view> hashSet;
    //     while(left <= right){
    //         int mid = left + ((right-left)>>1);
    //         bool hasDuplicates = false;
    //         for(int i = 0; i < len-mid+1; ++i){
    //             auto [it, inserted] =  hashSet.insert(sv.substr(i, mid));
    //             if(!inserted){
    //                hasDuplicates = true;
    //                longest = *it;
    //                break;                    
    //             }
    //         }
    //         if(hasDuplicates){
    //             left = mid+1;
    //         }else{
    //             right = mid-1;
    //         }
    //         hashSet.clear();
    //     }
    //     return string(longest);
    // }
};
