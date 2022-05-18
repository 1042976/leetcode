class Solution {
public:
    //Time O(nlogn), Space O(logn)
    // string customSortString(string order, string s) {
    //     unordered_map<char, int> hashMap;
    //     for(int i = 0; i < order.length(); ++i){
    //         hashMap[order[i]] = i;
    //     }
    //     int i = 0;
    //     int j = s.length()-1;
    //     while(i <= j){
    //         if(hashMap.count(s[i]) == 0){
    //             swap(s[i], s[j--]);
    //         }else{
    //             ++i;
    //         }
    //     }
    //     sort(s.begin(), s.begin()+j+1, [&hashMap](const char &a, const char &b)->bool{
    //        return hashMap[a] < hashMap[b]; 
    //     });
    //     return s;
    // }
    //Time O(n), Space O(1)
    string customSortString(string order, string s){
        vector<int> arr(26, 0);
        for(const auto &c : s){
            ++arr[c-'a'];
        }
        string res = "";
        for(const auto &c : order){
            res.append(arr[c-'a'], c);
            arr[c-'a'] = 0;
        }
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] != 0){
                res.append(arr[i], i+'a');
            }
        }
        return res;
    }
};
