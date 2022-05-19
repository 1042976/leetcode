class Solution {
public:
    // bool compare(const string &str1, const string &str2){
    //     if(str1.length() != str2.length()){
    //         return false;
    //     }
    //     int d = (str2[0]-str1[0]+26)%26;
    //     for(int i = 1; i < str1.length(); ++i){
    //         if((str2[i]-str1[i]+26)%26 != d){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // void pushStr(vector<vector<string> > &res, string str){
    //     for(auto &arr : res){
    //         if(compare(arr[0], str)){
    //             arr.emplace_back(str);
    //             return;
    //         }
    //     }
    //     res.emplace_back(vector<string>{str});
    // }
    // //Time O(n^2m^2), Space O(1)
    // vector<vector<string>> groupStrings(vector<string>& strings) {
    //     vector<vector<string> > res;
    //     res.emplace_back(vector<string>{strings[0]});
    //     for(int i = 1; i < strings.size(); ++i){
    //         pushStr(res, strings[i]);
    //     }
    //     return res;
    // }
    
    string getHash(string &str){
        string hashValue;
        for(int i = 1; i < str.length(); ++i){
            hashValue.push_back((str[i]-str[i-1]+26)%26);
        }
        return hashValue;
    }
    //Time O(nm), Space O(nm)
    vector<vector<string>> groupStrings(vector<string>& strings){
        unordered_map<string, vector<string> > hashMap;
        for(auto &str : strings){
            string hashValue = getHash(str);
            hashMap[hashValue].emplace_back(str);
        }
        vector<vector<string> > res;
        for(const auto &[hashValue, arr] : hashMap){
            res.emplace_back(arr);
        }
        return res;
    }
};
