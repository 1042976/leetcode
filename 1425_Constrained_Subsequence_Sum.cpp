class Solution {
public:
    //Time O(N), Space O(N+k)
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        deque<int> D;
        D.emplace_back(dp[0]);
        for(int i = 1; i <= k; ++i){
            dp[i] = max(nums[i], nums[i]+D.front());
            while(!D.empty() && D.back() < dp[i]){
                D.pop_back();
            }
            D.emplace_back(dp[i]);
        }
        for(int i = k+1; i < n; ++i){
            if(D.front() == dp[i-k-1]){
                D.pop_front();
            }
            dp[i] = max(nums[i], nums[i]+D.front());
            while(!D.empty() && D.back() < dp[i]){
                D.pop_back();
            }
            D.emplace_back(dp[i]);
        }
        int maxSum = INT_MIN;
        for(int i = 0; i < n; ++i){
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
    
};
