class Solution {
public:
    // vector<vector<int> > permuteHelper(vector<int>& nums, int r){
    //     if(r == 0){
    //         return vector<vector<int> >{vector<int>{nums[r]}};
    //     }
    //     vector<vector<int> >  permutations = permuteHelper(nums, r-1);
    //     int size = permutations.size();
    //     for(int i = 0; i < size; ++i){
    //         for(int j = 0; j < permutations[i].size(); ++j){
    //             vector<int> arr = permutations[i];
    //             arr.insert(arr.begin()+j, nums[r]);
    //             permutations.emplace_back(arr);
    //         }
    //         permutations[i].emplace_back(nums[r]);
    //     }
    //     return permutations;
    // }
    // //Time O(N*N!), Space O(N^2)
    // vector<vector<int>> permute(vector<int>& nums) {
    //     return permuteHelper(nums, nums.size()-1);
    // }
    vector<vector<int> > res;
    void backtrack(vector<int>& nums, int first){
        if(first == nums.size()-1){
            res.emplace_back(nums);
            return;
        }
        for(int i = first; i < nums.size(); ++i){
            swap(nums[i], nums[first]);
            backtrack(nums, first+1);
            swap(nums[i], nums[first]);
        }
    }
    //Time O(N*N!), Space O(N)
    vector<vector<int>> permute(vector<int>& nums){
        backtrack(nums, 0);
        return res;
    }
};
