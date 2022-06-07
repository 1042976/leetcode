class Solution {
public:
    //Time O(N^3), Space O(logN)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {        
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-3; ++i){
            if(i >= 1 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < n-2; ++j){
                if(j >= i+2 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j+1, g = n-1;
                int target2 = target-nums[i]-nums[j];
                while(k < g){
                    if(k >= j+2 && nums[k] == nums[k-1]){
                        ++k;
                        continue;
                    }
                    if(nums[k]+nums[g] == target2){
                        res.emplace_back(vector<int>{nums[i],nums[j], nums[k++], nums[g--]});
                    }else if(nums[k]+nums[g] > target2){
                        --g;
                    }else{
                        ++k;
                    }
                }
            }
        }
        return res;
    }
};
