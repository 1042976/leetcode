class Solution {
public:
    //Time O(n), Space O(n)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        int sum = 0;
        int res = 0;
        for(const auto &x : nums){
            sum += x;
            if(sum == k){
                ++res;
            }
            if(hashMap.count(sum-k)){
                res += hashMap[sum-k];
            }
            ++hashMap[sum];
        }
        return res;
    }
};
