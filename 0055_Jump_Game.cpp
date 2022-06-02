class Solution {
public:
    //Time O(n), Space O(n)
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<bool> dp(n, false);
    //     dp[n-1] = true;
    //     for(int i = n-2; i >= 0; --i){
    //         for(int j = 1; j <= nums[i]; ++j){
    //             if(dp[i+j]){
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[0];
    // }
    
    //Time O(n), Space O(1)
    bool canJump(vector<int>& nums){
        int n = nums.size();
        int i = n-2;
        bool status = true;
        while(i >= 0){
            if(nums[i] > 0){
                --i;
                continue;
            }else{
                int j = i--;
                status = false;
                while(i >= 0){
                    if(nums[i] > (j-i)){
                        status = true;
                        break;
                    }else{
                        --i;
                    }
                }
            }
        }
        return status;
    }
    
    // Time O(n), Space O(1)
    // bool canJump(vector<int>& nums){
    //     int n = nums.size();
    //     int lastValid = n-1;
    //     for(int i = n-2; i >= 0; --i){
    //         if(i+nums[i] >= lastValid){
    //             lastValid = i;
    //         }
    //     }
    //     return lastValid == 0;
    // }
};
