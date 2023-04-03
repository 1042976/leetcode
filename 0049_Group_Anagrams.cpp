class Solution {
public:
    //T-O(NK), S-O(NK), N is the number of strings while K is the max length among strings
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string> > hashMap;
//         for(const auto &str: strs){
//             string digits = getDigits(str);
//             hashMap[digits].emplace_back(str);      
//         }
//         vector<vector<string> > res;
//         auto it = hashMap.begin();
//         while(it != hashMap.end()){
//             res.emplace_back(it->second);
//             ++it;
//         }
//         return res;
//     }
    
//     string getDigits(const string& str){
//         string res(26, '0');
//         for(const auto &c : str){
//             ++res[c-'a'];
//         }
//         return res;
//     }
    
    //Time O(N), Space O(K). N is the total number of characters in the input, while K is the number of unique representations for the strings.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, int > hashMap;
        for(const auto &str: strs){
            string digits = getDigits(str);
            if(hashMap.count(digits) == 0){
                hashMap[digits] = res.size();
                res.emplace_back(vector<string>{str});
            }else{
                res[hashMap[digits]].emplace_back(str);
            }     
        }
        return res;
    }
    
    string getDigits(const string& str){
        string res(26, '0');
        for(const auto &c : str){
            ++res[c-'a'];
        }
        return res;
    }
    
};
