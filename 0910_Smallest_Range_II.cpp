class Solution {
public:
    //Time O(NlogN), Space O(logN)
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[n-1]-nums[0];
        int high = nums[n-1]-k, low = nums[0]+k;
        for(int i = 0; i < n-1; ++i){
            int a = nums[i]+k, b = nums[i+1]-k;
            int high = max(nums[n-1]-k, a);
            int low = min(nums[0]+k, b);
            res = min(res, high-low);
        }
        return res;
    }
};
