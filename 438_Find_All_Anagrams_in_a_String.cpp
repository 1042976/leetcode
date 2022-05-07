class Solution {
public:
    //T-O(M+N), S-O(K)
    // vector<int> findAnagrams(string s, string p) {
    //     unordered_map<char, pair<int, bool> > hashMap;
    //     for(const auto &c : p){
    //         ++hashMap[c].first;
    //     }
    //     int d = hashMap.size();
    //     auto it = hashMap.begin();
    //     while(it != hashMap.end()){
    //         it->second.second = false;
    //         ++it;
    //     }
    //     vector<int> res;
    //     for(int i = 0; i < s.length(); ++i){
    //         if(i >= p.length()){
    //             char last = s[i-p.length()];
    //             if(hashMap.count(last)){
    //                 ++hashMap[last].first;
    //                 if(hashMap[last].first > 0 && hashMap[last].second == true){
    //                     ++d;
    //                     hashMap[last].second = false;
    //                 }
    //             }
    //         }
    //         if(hashMap.count(s[i])){
    //             --hashMap[s[i]].first;
    //             if(hashMap[s[i]].first == 0){
    //                 --d;
    //                 hashMap[s[i]].second = true;
    //             }
    //         }
    //         if(d == 0){
    //             res.emplace_back(i-p.length()+1);
    //         }
    //     }
    //     return res;
    // }
    
    //T-O(M+N), S-O(1)
    vector<int> findAnagrams(string s, string p){
        int M = s.length(), N = p.length();
        if(N > M){
            return vector<int>{};
        }
        vector<int> pr(26, 0), sr(26,0);
        vector<int> res;
        for(const auto &c : p){
            ++pr[c-'a'];
        }
        for(int i = 0; i < N; ++i){
            ++sr[s[i]-'a'];
        }
        if(sr == pr){
            res.emplace_back(0);
        }
        for(int i = N; i < M; ++i){
            --sr[s[i-N]-'a'];
            ++sr[s[i]-'a'];
            if(sr == pr){
                res.emplace_back(i-N+1);
            }
        }
        return res;
    }
};
