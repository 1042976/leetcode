class Solution {
public:
    //Time O(N), Space O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(const auto &n : nums){
            diff ^= n;
        }
        int bitMask = diff == INT_MIN? INT_MIN : diff & (-diff);
        int x = 0;
        for(const auto &n : nums){
            if(n & bitMask){
                x ^= n;
            }
        }
        int y = diff ^ x;
        return vector<int>{x, y};
    }
};
