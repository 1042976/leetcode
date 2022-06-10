class Solution {
public:
    //Time O(N), Space O(1)
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for(const auto &n : nums){
            seenOnce = (~seenTwice) & (seenOnce^n);
            seenTwice = (~seenOnce) & (seenTwice^n);
        }
        return seenOnce;
    }
};
