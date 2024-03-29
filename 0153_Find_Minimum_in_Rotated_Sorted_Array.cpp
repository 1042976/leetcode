class Solution {
public:
    // Time O(logN), Space O(1)
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + ((right-left)>>1);
            if(nums[mid] >= nums[left] && nums[mid] <= nums[right]){
                return nums[left];
            }else if(nums[mid] >= nums[left] && nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
};
