class Solution {
public:
    //Time O(N), Space O(1)
    int majorityElement(vector<int>& nums) {
        int a = nums[0], count = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == a){
                ++count;
            }else{
                if(count == 0){
                    a = nums[i];
                    count = 1;
                }else{
                    --count;
                }
            }
        }
        return a;
    }
};
