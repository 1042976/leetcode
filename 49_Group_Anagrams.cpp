class Solution {
public:
    //T-O(N*K+N*A), S-O(N*K+N*A)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > hashMap;
        for(const auto &str: strs){
            string digits = getDigits(str);
            hashMap[digits].emplace_back(str);      
        }
        vector<vector<string> > res;
        auto it = hashMap.begin();
        while(it != hashMap.end()){
            res.emplace_back(it->second);
            ++it;
        }
        return res;
    }
    
    string getDigits(const string& str){
        string s(26, '0');
        for(const auto &c : str){
            ++s[c-'a'];
        }
        return res;
    }
    
};
