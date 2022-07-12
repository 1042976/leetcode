class Solution {
public:
    unordered_map<int, vector<int> > hashMap;
    //Time O(N), Space O(N)
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            hashMap[nums[i]].emplace_back(i);
        }
        srand(time(NULL));
    }
    
    //Time O(1), Space O(1)
    int pick(int target) {
        vector<int>& indices = hashMap[target];
        return indices[rand()%indices.size()];
    }
};

// class Solution {
// public:
//     vector<int> arr;

//     Solution(vector<int>& nums) {
//         arr.swap(nums);
//         srand(time(NULL));
//     }
    
//     int pick(int target) {
//         int count = 0;
//         int idx = -1;
//         for(int i = 0; i < arr.size(); ++i){
//             if(arr[i] == target){
//                 ++count;
//                 if(rand()%count == 0){
//                     idx = i;
//                 }
//             }
//         }
//         return idx;
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
