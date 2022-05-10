class Solution {
public:
    //Time O(n), Space O(1).
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(const auto &x :nums){
            if(x == 0){
                return 0;
            }else if(x < 0){
                sign *= -1;
            }
        }
        return sign;
    }
};
