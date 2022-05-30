class Solution {
public:
    //Time O(N), Space O(1)
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int dp0 = nums[0], dp1 = nums[1];
        for(int i = 2; i < nums.size(); ++i){
            if(i%2 == 0){
                dp0 = max(dp0+nums[i], dp1+nums[i]-nums[i-1]);
            }else{
                dp1 = max(dp1+nums[i], dp0+nums[i]-nums[i-1]);
            }
        }
        return dp0 > dp1? dp0 : dp1;
    }
};
