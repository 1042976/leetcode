class Solution {
public:
    int twoSumClosest(vector<int>& nums, int i, int j, int target){
        int res = INT_MAX;
        while(i < j){
            int dist = target-nums[i]-nums[j];
            if(dist == 0){
                return 0;
            }else if(dist < 0){
                --j;
            }else{
                ++i;
            }
            if(abs(dist) < abs(res)){
                res = dist;
            }
        }
        return res;
    }
    //Time O(N^2), Space O(logN)
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-2; ++i){
            int target2 = target-nums[i];
            int dist = twoSumClosest(nums, i+1, n-1, target2);
            if(abs(minDist) > abs(dist)){
                minDist = dist;
            }
            if(minDist == 0){
                return target;
            }
        }
        return target-minDist;
    }
};
