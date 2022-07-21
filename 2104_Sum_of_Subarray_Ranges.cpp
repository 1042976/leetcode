class Solution {
public:
    //Time O(n^2), Space O(n^2)
    // long long subArrayRanges(vector<int>& nums) {
    //     long long res = 0;
    //     int n = nums.size();
    //     pair<int, int> dp[n][n];
    //     for(int i = 0; i < n; ++i){
    //         dp[i][i].first = nums[i];
    //         dp[i][i].second = nums[i];
    //     }
    //     for(int len = 2; len <= n; ++len){
    //         for(int i = 0; i+len <= n; ++i){
    //             int j = i+len-1;
    //             dp[i][j].first = min(dp[i][j-1].first,nums[j]);
    //             dp[i][j].second = max(dp[i][j-1].second,nums[j]);
    //             res += dp[i][j].second-dp[i][j].first;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(N^2), Space O(1)
    // long long subArrayRanges(vector<int>& nums) {
    //     long long res = 0;
    //     int n = nums.size();
    //     for(int i = 0; i < n; ++i){
    //         int minVal = nums[i];
    //         int maxVal = nums[i];
    //         for(int j = i+1; j < n; ++j){
    //             minVal = min(minVal, nums[j]);
    //             maxVal = max(maxVal, nums[j]);
    //             res += maxVal-minVal;
    //         }
    //     }
    //     return res;
    // }
    //Time O(N), Space O(N)
        long long subArrayRanges(vector<int>& nums) {
            long long res = 0;
            stack<int> st;
            st.emplace(-1);
            nums.emplace_back(INT_MIN);
            for(int i = 0; i < nums.size(); ++i){
                while(st.top() != -1 && nums[st.top()] > nums[i]){
                    int j = st.top();
                    st.pop();
                    int k = st.top();
                    res -= (long long)nums[j]*(j-k)*(i-j);
                }
                st.emplace(i);
            }
            st.pop();
            nums.back() = INT_MAX;
            for(int i = 0; i < nums.size(); ++i){
                while(st.top() != -1 && nums[st.top()] < nums[i]){
                    int j = st.top();
                    st.pop();
                    int k = st.top();
                    res += (long long)nums[j]*(j-k)*(i-j);
                }
                st.emplace(i);
            }
            return res;
        }
};
