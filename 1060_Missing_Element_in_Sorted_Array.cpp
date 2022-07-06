class Solution {
public:
    //Time O(N), Space O(1)
    // int missingElement(vector<int>& nums, int k) {
    //     int marker = nums[0]+k;
    //     for(int i = 1; i < nums.size(); ++i){
    //         if(nums[i] <= marker){
    //             ++marker;
    //         }else{
    //             break;
    //         }
    //     }
    //     return marker;
    // }
    
    int getNumOfMissings(vector<int>& nums, int idx){
        return nums[idx]-nums[0]-idx;
    }
    //Time O(logN), Space O(1)
    int missingElement(vector<int>& nums, int k) {
        int N = nums.size();
        if(getNumOfMissings(nums, N-1) < k){
            return k-getNumOfMissings(nums, N-1)+nums.back();
        }
        int left = 0, right = N-1;
        while(left < right){
            int mid = left + ((right-left)>>1);
            int a = getNumOfMissings(nums, mid);
            int b = getNumOfMissings(nums, mid+1);
            if(a < k && b >= k){
                return k-a+nums[mid];
            }else if(a >= k){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return k-getNumOfMissings(nums, left)+nums[left];
    }
};
