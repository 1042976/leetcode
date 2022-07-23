class Solution {
public:
    // unordered_map<char, vector<int> > hashMap;
    // vector<string> res;
    // bool check(vector<string>& words, int i, int start, int count){
    //     string &word = words[i];
    //     if(start == word.length()){
    //         return count >= 2;
    //     }
    //     if(hashMap.count(word[start])){
    //         for(const int &j : hashMap[word[start]]){
    //             string &other = words[j];
    //             if(word.compare(start, other.length(), other) == 0){
    //                 if(check(words, i, start+other.length(), count+1)){
    //                     return true;
    //                 }
    //             }
    //         }
    //     }
    //     return false;
    // }
    // //Time O(N^2 * L), Space O(N), N is the size of words while L is the length of a single word.
    // vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    //     sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{
    //        return a.length() < b.length(); 
    //     });
    //     for(int i = 0; i < words.size(); ++i){
    //         if(check(words, i, 0, 0)){
    //             res.emplace_back(words[i]);
    //         }
    //         hashMap[words[i][0]].emplace_back(i);
    //     }
    //     return res;
    // }
    
    unordered_set<string> hashSet;
    vector<string> res;
    bool check(const string &word){
        int len = word.length();
        bool dp[len+1];
        dp[0] = true;
        for(int i = 1; i <= len; ++i){
            dp[i] = false;
        }
        for(int i = 1; i <= len; ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j]){
                    if(hashSet.count(word.substr(j, i-j))){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
    //Time O(N(logN+L^3)), Space O(N+L), N is the size of words while L is the length of a single word.
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b)->bool{
           return a.length() < b.length(); 
        });
        for(const auto &word : words){
            if(check(word)){
                res.emplace_back(word);
            }
            hashSet.insert(word);
        }
        return res;
    }
};
