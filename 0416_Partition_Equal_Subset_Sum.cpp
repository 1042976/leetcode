class Solution {
public:
    // vector<unordered_map<int, int> > memo;
    // bool canPartition(vector<int>& nums, int balance, int cur){
    //     if(cur == nums.size()){
    //         return false;
    //     }
    //     if(memo[cur].count(balance)){
    //         return memo[cur][balance];
    //     }
    //     if(nums[cur] == balance){
    //         memo[cur][balance] = true;
    //     }else if(nums[cur] > balance){
    //         memo[cur][balance] = false;
    //     }else{
    //         memo[cur][balance] = canPartition(nums, balance-nums[cur], cur+1) || canPartition(nums, balance, cur+1);
    //     }
    //     return memo[cur][balance];
    // }
    // // Time O(2^N), Space O(N^M). N is the size of the nums, M is hald sum of the nums.
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if (sum%2){
    //         return false;
    //     }
    //     sum >>= 1;
    //     memo = vector<unordered_map<int, int> >(nums.size());
    //     sort(nums.begin(), nums.end());
    //     return canPartition(nums, sum, 0);
    // }

    // Time O(MN), Space O(MN), where M is the sum of nums, N is the size of nums.
    // bool canPartition(vector<int>& nums){
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if(sum%2){
    //         return false;
    //     }
    //     sum >>= 1;
    //     int n = nums.size();
    //     bool dp[n+1][sum+1];
    //     for(int i = 0; i <= n; ++i){
    //         dp[i][0] = true;
    //     }
    //     for(int i = 1; i <= sum; ++i){
    //         dp[n][i] = false;
    //     }
    //     for(int i = n-1; i >= 0; --i){
    //         for(int j = 1; j <= sum; ++j){
    //             dp[i][j] = dp[i+1][j] || (j < nums[i]? false : dp[i+1][j-nums[i]]);
    //         }
    //     }
    //     return dp[0][sum];
    // }

    // Time O(MN), Space O(M), M is the sum of nums while N is the size of nums.
    bool canPartition(vector<int>& nums){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2){
            return false;
        }
        sum >>= 1;
        int n = nums.size();
        bool dp[sum+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(int i = n-1; i >= 0; --i){
            for(int j = sum; j > 0; --j){
                if(j >= nums[i]){
                    dp[j] |= dp[j-nums[i]];
                }
            }
        }
        return dp[sum];
    }
};
