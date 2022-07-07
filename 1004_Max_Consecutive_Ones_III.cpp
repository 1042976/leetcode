class Solution {
public:
    //Time O(N), Space O(1)
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for(right = 0; right < nums.size(); ++right){
            if(nums[right] == 0){
               --k;
            }
            if(k < 0){
               if(nums[left++] == 0){
                   ++k;
               }                
            }
        }
        return right-left;
    }
};
