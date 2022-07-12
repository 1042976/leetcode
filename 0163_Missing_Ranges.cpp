class Solution {
public:
    //Time O(N), Space O(1)
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        nums.emplace_back(upper+1);
        for(const auto &x : nums){
            if(lower == x-1){
                res.emplace_back(to_string(lower));
            }else if(lower < x-1){
                res.emplace_back(to_string(lower)+"->"+to_string(x-1));
            }
            lower = x+1;
        }
        return res;
    }
};
