class Solution {
public:
    //Time O(N), Space O(1)
    int maxProduct(vector<int>& nums) {
        int maxVal = nums[0], dpMax = nums[0], dpMin = nums[0]; 
        for(int i = 1; i < nums.size(); ++i){
            int a = dpMax*nums[i];
            int b = dpMin*nums[i];
            dpMax = max(max(a, b), nums[i]);
            dpMin = min(min(a, b), nums[i]);
            maxVal = max(maxVal, dpMax);
        }
        return maxVal;
    }
};
