class Solution {
public:
    //Time O(N), Space O(1)
    int getMaxLen(vector<int>& nums) {
        int maxLen = 0;
        int A = 0, B = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0){
                maxLen = max(maxLen, ++A);
                if(B > 0){
                    ++B;
                }
            }else if(nums[i] < 0){  
                int tmp = A;
                A = B == 0? 0 : B+1;
                B = tmp + 1;
                maxLen = max(maxLen, A);
            }else{
                A = 0;
                B = 0;
            }
        }
        return maxLen;
    }
};
