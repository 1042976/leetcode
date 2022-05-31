class Solution {
public:

    //Time O(N), Space O(1)
    // int findDuplicate(vector<int>& nums) {
    //     int i = 0;
    //     while(nums[i] > 0){
    //         nums[i] = -nums[i];
    //         i = -nums[i];
    //     }
    //     for(auto &x : nums){
    //         x = abs(x);
    //     }
    //     return i;
    // }
    
    //Time O(N), Space O(1)
    int findDuplicate(vector<int>& nums){
        int tortoise = 0, hare = 0;
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(nums[tortoise] != nums[hare]);     
        tortoise = 0;
        while(nums[tortoise] != nums[hare]){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return nums[tortoise];
    }
};
