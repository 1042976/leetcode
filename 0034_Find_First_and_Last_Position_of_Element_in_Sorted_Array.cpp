class Solution {
public:
    int getLeftBoundary(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int m = l+((r-l)>>1);
            if(nums[m] == target){
                if(m == 0 || nums[m-1] != target){
                    return m;
                }else{
                    r = m-1;
                }
            }else if(nums[m] < target){
                l = m+1;
            }else{
                r = m-1;
            }            
        }
        return -1;
    }
    int getRightBoundary(vector<int>& nums, int target, int l, int r){
        while(l <= r){
            int m = l+((r-l)>>1);
            if(nums[m] == target){
                if(nums[m] == target){
                    if(m == nums.size()-1 || nums[m+1] != target){
                        return m;
                    }else{
                        l = m+1;
                    }
                }
            }else if(nums[m] < target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return -1;
    }
    //Time O(logN), Space O(1)
    vector<int> searchRange(vector<int>& nums, int target) {

        int lt = getLeftBoundary(nums, target, 0, nums.size()-1);
        int rt = getRightBoundary(nums, target, 0, nums.size()-1);
        return vector<int>{lt, rt};

    }
};
