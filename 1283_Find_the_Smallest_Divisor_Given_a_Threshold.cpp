class Solution {
public:
    //Time O(N), Space O(1)
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e+6;
        while(left < right){
            int mid = left + ((right-left)>>1);
            int sum = 0;
            for(const auto &x : nums){
                sum += (x+mid-1)/mid;
                if(sum > threshold){
                    break;
                }
            }
            if(sum <= threshold){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};
