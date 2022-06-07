class Solution {
public:
    int twoSumSmaller(vector<int>& nums, int i, int j, int target){
        int res = 0;
        while(i < j){
            if(nums[i]+nums[j] < target){
                res += (j-i);
                ++i;
            }else{
                --j;
            }
        }
        return res;
    }
    //Time O(N^2), Space O(logN)
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int size = nums.size();
        for(int i = 0; i < size-2; ++i){
            int target2 = target-nums[i];
            res += twoSumSmaller(nums, i+1, size-1, target2);
        }
        return res;
    }
};
