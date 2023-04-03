class Solution {
public:
    //Time O(N), Space O(N)
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> D;
        long long sums[n+1];
        sums[0] = 0;
        for(int i = 0; i < n; ++i){
            sums[i+1] = sums[i] + nums[i];
        }
        D.emplace_back(0);
        int minLen = INT_MAX;
        for(int j = 1; j <= n; ++j){
            while(!D.empty() && sums[j]-sums[D.front()] >= k){
                minLen = min(minLen, j-D.front());
                D.pop_front();
            }
            while(!D.empty() && sums[D.back()] >= sums[j]){
                D.pop_back();
            }
            D.emplace_back(j);
        }
        return minLen == INT_MAX? -1 : minLen;
    }
};
