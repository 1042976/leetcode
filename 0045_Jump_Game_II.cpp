class Solution {
public:
    // vector<int> memo;
    // int dp(vector<int>& nums, int idx){
    //     if(idx == nums.size()-1){
    //         return 0;
    //     }
    //     if(memo[idx] > 0){
    //         return memo[idx];  
    //     }
    //     int minJumps = INT_MAX;
    //     for(int i = 1; i <= nums[idx] && idx + i < nums.size(); ++i){
    //         int nextJumps = dp(nums, idx+i);
    //         if(nextJumps != INT_MAX){
    //             minJumps = min(minJumps, 1+nextJumps);
    //         }
    //     }
    //     memo[idx] = minJumps;
    //     return minJumps;
    // }
    // //Time O(S), Space O(N), S is the sum of all values in nums, N is the size of nums.
    // int jump(vector<int>& nums) {
    //     memo.resize(nums.size(), 0);
    //     return dp(nums, 0);
    // }
    
    //Time O(N^2), Space O(N), N is size of nums
    // int jump(vector<int>& nums){
    //     int n = nums.size();
    //     int dp[n];
    //     dp[n-1] = 0;
    //     for(int i = 0; i < n-1; ++i){
    //         dp[i] = INT_MAX;
    //     }
    //     for(int i = n-2; i >= 0; --i){
    //         for(int j = 1; j <= nums[i] && i+j < n; ++j){
    //             if(dp[i+j] < INT_MAX){
    //                 dp[i] = min(dp[i], 1+dp[i+j]);
    //             }
    //         }
    //     }
    //     return dp[0];
    // }
    
    // int jump(vector<int>& nums){
    //     int n = nums.size();
    //     if(n == 1){
    //         return 0;
    //     }
    //     int i = 0, j = 1, farthest = nums[0], jumps = 0;
    //     while(farthest < n-1){
    //         int k = j;
    //         while(j <= farthest){
    //             if(nums[j] >= nums[k]){
    //                 k = j;
    //             }
    //             ++j;
    //         }
    //         i = k;
    //         farthest = i+nums[i];
    //         k = j;
    //         ++jumps;
    //     }
    //     return jumps+1;
    // }
    
    //Time O(N), Space O(1)
    int jump(vector<int>& nums){
        int n = nums.size();
        int curEnd = 0, farthest = 0, jumps = 0;
        for(int i = 0; i < n-1; ++i){
            farthest = max(farthest, i + nums[i]);
            if(i == curEnd){
                curEnd = farthest;
                ++jumps;
            }
        }
        return jumps;
    }
};
