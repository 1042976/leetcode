class Solution {
public:
    //Time O(Nlog(L(N-M))), Space O(1)
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        for(const auto &x : nums){
            left = max(x, left);
        }
        int right = left*(nums.size()-m+1);
        while(left < right){
            int mid = left + ((right-left)>>1);
            int cuts = 0, sum = 0;
            for(const auto &x : nums){
               if(sum + x > mid){
                   ++cuts;
                   sum = x;
               }else{
                   sum += x;
               }
            }
            if(cuts > m-1){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
