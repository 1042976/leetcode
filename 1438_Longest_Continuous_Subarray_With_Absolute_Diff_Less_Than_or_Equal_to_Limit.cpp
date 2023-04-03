class Solution {
public:
    //Time O(N), Space O(N)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int left = 0, right = 0;
        while(right < nums.size()){
            while(!maxD.empty() && maxD.back() < nums[right]){
                maxD.pop_back();
            }
            maxD.emplace_back(nums[right]);
            while(!minD.empty() && minD.back() > nums[right]){
                minD.pop_back();
            }
            minD.emplace_back(nums[right]);
            if(maxD.front()-minD.front() > limit){
                if(maxD.front() == nums[left]){
                    maxD.pop_front();
                }
                if(minD.front() == nums[left]){
                    minD.pop_front();
                }
                ++left;
            }
            ++right;
        }
        return right-left;
    }
};
