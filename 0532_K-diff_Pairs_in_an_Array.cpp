class Solution {
public:
    // string toStr(int x, int y){
    //     return to_string(x) + "," + to_string(y);
    // }
    // //Time O(N), Space O(N)
    // int findPairs(vector<int>& nums, int k) {
    //     int res = 0;
    //     unordered_set<int> record;
    //     unordered_set<string> pairs;
    //     for(const auto &x : nums){
    //         int a = x-k, b = x+k;
    //         if(record.count(a)){
    //             string strXA = toStr(x, a);
    //             if(pairs.count(strXA) == 0){
    //                 ++res;
    //                 pairs.insert(strXA);
    //             }         
    //         }
    //         if(record.count(b)){
    //             string strBX = toStr(b, x);
    //             if(pairs.count(strBX) == 0){
    //                 ++res;
    //                 pairs.insert(strBX);
    //             }   
    //         }
    //         record.insert(x);
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(N)
    int findPairs(vector<int>& nums, int k){
        unordered_map<int, int> hashMap;
        for(const auto &x : nums){
            ++hashMap[x];
        }
        int count = 0;
        for(const auto &[key, val] : hashMap){
            int target = key-k; //can also be key+k
            if(hashMap.count(target)){
                if(k == 0 && hashMap[target] > 1 || k > 0){
                    ++count;
                }
            }
        }
        return count;
    }
};
