class Solution {
public:
    //T(n^3), S-O(n^2)
//     int maxCoins(vector<int>& nums) {
//         nums.insert(nums.begin(), 1);
//         nums.emplace_back(1);
//         vector<vector<int> > memo(nums.size(), vector<int>(nums.size(), -1));
//         return dp(memo, nums, 1, nums.size()-2);
//     }
    
//     int dp(vector<vector<int> >& memo, vector<int>& nums, int left, int right){
//         if(right < left){
//             return 0;
//         }
//         if(memo[left][right] != -1){
//             return memo[left][right];
//         }
//         int maxCoins = 0;
//         for(int i = left; i <= right; ++i){
//             int remaining = dp(memo, nums, left, i-1) + dp(memo, nums, i+1, right);
//             int coins = nums[left-1]*nums[i]*nums[right+1];
//             maxCoins = max(maxCoins, remaining+coins);
//         }
//         memo[left][right] = maxCoins;
//         return maxCoins;
//     }
    
    //T-O(n^3), S-O(n^2)
    int maxCoins(vector<int>& nums){
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        int n = nums.size();
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
        for(int left = n-2; left >= 1; --left){
            for(int right = left; right <= n-2; ++right){
                for(int i = left; i <= right; ++i){
                    int remaining = dp[left][i-1]+dp[i+1][right];
                    int coins = nums[left-1]*nums[i]*nums[right+1];
                    dp[left][right] = max(dp[left][right], remaining+coins);
                }
            }
        }
        return dp[1][n-2];
    }
};
