class Solution {
public:
    //Time O(N), Space O(1)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int missing = n;
    //     for(int i = 0; i < nums.size(); ++i){
    //         while(nums[i] !=n && nums[i] != i){
    //             swap(nums[i], nums[nums[i]]);
    //         }
    //         if(nums[i] == n){
    //             missing = i;
    //         }
    //     }
    //     return missing;
    // }
    
    //Time O(N), Space O(1)
    // int missingNumber(vector<int>& nums) {
    //     int res = 0;
    //     for(int i = 0; i < nums.size(); ++i){
    //         res ^= (i+1)^(nums[i]);
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int sum2 = 0;
        for(int i = 0; i < n; ++i){
            sum2 += nums[i];
        }
        return sum-sum2;
    }
};
