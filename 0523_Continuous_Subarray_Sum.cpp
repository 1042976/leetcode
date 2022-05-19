class Solution {
public:
    //Time O(n), Space O(n)
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int dp = 0;
        for(int i = 0; i < nums.size(); ++i){
            dp = (dp+nums[i])%k;
            if(dp == 0 && i > 0){
                return true;
            }else if(hashMap.count(dp) == 1){
                if(i > hashMap[dp]+1){
                    return true;
                }
            }else{
                hashMap[dp] = i;
            }
        }
        return false;
    }
};
