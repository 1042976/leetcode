class Solution {
public:
    //Time O(n), Space O(1)
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(i >= 1){
            if(nums[i-1] < nums[i]){
                break;
            }
            --i;
        }
        reverse(nums.begin()+i, nums.end());
        if(i > 0){
            int j = i;
            while(j < nums.size()){
                if(nums[j] > nums[i-1]){
                    break;
                }
                ++j;
            }
            swap(nums[i-1], nums[j]);
        }
    }
};
