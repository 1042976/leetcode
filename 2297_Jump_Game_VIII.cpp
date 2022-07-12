class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        long long dp[n];
        dp[0] = 0;
        stack<int> one, two;
        one.emplace(0);
        two.emplace(0);
        for(int i = 1; i < n; ++i){
            dp[i] = LONG_LONG_MAX;
            while(!one.empty() && nums[one.top()] <= nums[i]){
                dp[i] = min(dp[i], dp[one.top()]+costs[i]);
                one.pop();
            }
            while(!two.empty() && nums[two.top()] > nums[i]){
                dp[i] = min(dp[i], dp[two.top()]+costs[i]);
                two.pop();
            }
            one.emplace(i);
            two.emplace(i);
        }
        return dp[n-1];
    }
};
