class Solution {

public:
    //Time O(n^2), Space O(logn)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() <= 2){
            return res;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-2 && nums[i] <= 0){
            int j = i+1, k = nums.size()-1;
            while(j < k && nums[k] >= 0){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum > 0){
                    --k;
                }else if(sum < 0){
                    ++j;
                }else{
                    res.emplace_back(vector<int>{nums[i],nums[j++],nums[k--]});
                    while(j < k && nums[j-1] == nums[j]){
                        ++j;
                    }
                    while(j < k && nums[k+1] == nums[k]){
                        --k;
                    }                    
                }
            }
            ++i;
            while(i < nums.size()-2 && nums[i-1] == nums[i]){
                ++i;
            }
        }
        
        return res;      
    }
    
  
        
};
