class Solution {
public:
    //Time O(N), Space O(1)
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(i <nums.size() && j < nums.size()){
            if(nums[i] != 0){
                ++i;
            }else if(nums[j] == 0 || j <= i){
                ++j;
            }else{
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            }
        }
    }
};
