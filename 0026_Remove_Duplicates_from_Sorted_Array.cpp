class Solution {
public:
    int getNextUnique(vector<int>& nums, int idx, int curVal){
        while(idx < nums.size() && nums[idx] == curVal){
            ++idx;
        }
        return idx;
    }
    //Time O(N), Space O(1)
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int j = getNextUnique(nums, 1, nums[0]);
        while(j < nums.size()){
            swap(nums[i], nums[j]);
            j = getNextUnique(nums, j+1, nums[i++]);
        }
        return i;
    }
};
