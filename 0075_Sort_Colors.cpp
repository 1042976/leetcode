class Solution {
public:
    //Time O(N), Space O(1)
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int k = 0;
        while(k <= j){
            if(nums[i] == 0){
                ++i;
                k = i;
            }else if(nums[j] == 2){
                --j;
            }else{
                if(nums[k] == 1){
                    ++k;
                }else if(nums[k] == 0){
                    swap(nums[i++], nums[k]);
                }else{
                    swap(nums[j--], nums[k]);
                }
            }
        }
    }
};
