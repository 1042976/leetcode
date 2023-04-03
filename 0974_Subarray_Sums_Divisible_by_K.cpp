class Solution {
public:
    //Time O(N), Space O(k)
    int subarraysDivByK(vector<int>& nums, int k) {
        int memo[k];
        memset(memo, 0, sizeof(memo));
        memo[0] = 1;
        int sum = 0, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum = (sum+nums[i]%k+k)%k;
            res += memo[sum]++;
        }
        return res;
    }
};
