class Solution {
public:
    //Time O(N), Space O(1)
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for(const auto &x : nums){
            if(x <= first){
                first = x;
            }else if(x <= second){
                second = x;
            }else{
                return true;
            }
        }
        return false;
    }
};
