class Solution {
public:
    int mod = 1e+9+7;
    int a = 26;
    int N;
    int search(string& s, int L){
        unordered_map<int, vector<int> > hashMap;
        long long hashVal = 0;
        for(int i = 0; i < L; ++i){
            hashVal = ((hashVal*a) + (s[i]-'a'))%mod;
        }
        long long aExp = 1;
        for(int i = 1; i < L; ++i){
            aExp = (aExp*a)%mod;
        }
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
    //     }
    //     return string(longest);
    // }
};
