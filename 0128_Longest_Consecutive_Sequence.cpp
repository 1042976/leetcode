class Solution {
public:
    //Time O(N), Space O(N)
    int longestConsecutive(vector<int>& nums) {
        int maxLen;
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int toLeft, toRight;
        while(!hashSet.empty()){
            int cur = *hashSet.begin();
            hashSet.erase(cur);
            toLeft = cur-1;
            toRight = cur+1;
            while(hashSet.find(toLeft) != hashSet.end()){
                hashSet.erase(toLeft);
                --toLeft;
            }
            while(hashSet.find(toRight) != hashSet.end()){
                hashSet.erase(toRight);
                ++toRight;
            }
            maxLen = max(maxLen, toRight-toLeft-1);
        }
        return maxLen;
    }
};
