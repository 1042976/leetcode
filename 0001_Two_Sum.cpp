class Solution {
public:
    //Time O(N), Space O(N)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> indices(2), vals(2);
    //     unordered_set<int> hashSet;
    //     for(const auto &y : nums){
    //         if(hashSet.find(target-y) != end(hashSet)){
    //             vals[0] = target-y;
    //             vals[1] = y;
    //             break;
    //         }else{
    //             hashSet.insert(y);
    //         }
    //     }
    //     int j = 0;
    //     for(int i = 0; i < nums.size(); ++i){
    //         if(nums[i] == vals[j]){
    //             indices[j++] = i;
    //             if(j == 2){
    //                 break;
    //             }
    //         }   
    //     }
    //     return indices;
    // }
    
    //Time O(N), Space O(N)
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); ++i){
            int dif = target-nums[i];
            if(hashMap.find(dif) != end(hashMap)){
                return {hashMap[dif], i};
            }else{
                hashMap[nums[i]] = i;
            }
        }
        return {};
    }
};
