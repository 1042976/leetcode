class Solution {
public:
    //Time O(N), Space O(1)
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;
        for(const auto &n : nums){
            curSum += n;
            maxSum = max(curSum, maxSum);
            if(curSum < 0){
                curSum = 0;
            }
        }
        return maxSum;
    }
};
