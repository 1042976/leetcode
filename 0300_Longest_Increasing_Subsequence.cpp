class Solution {
public:
    int binarySearch(vector<int>& subsequence, int l, int r, int val){
        while(l < r){
            int m = l + ((r-l) >> 1);
            if(subsequence[m] >= val){
                if(m == 0 || subsequence[m-1] < val){
                    return m;
                }else{
                    r = m-1;
                }
            }else{
                l = m+1;
            }
        }
        return l;
    }
    //Time O(nlogn), Space O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subsequence{nums[0]};
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > subsequence.back()){
                subsequence.emplace_back(nums[i]);
            }else if(nums[i] < subsequence.back()){
                int j = binarySearch(subsequence, 0, subsequence.size()-1, nums[i]);
                subsequence[j] = nums[i];
            }
        }
        return subsequence.size();
    }
};
