class Solution {
public:
    //Time O(N), Space O(k)
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int> > D;
        D.emplace_back(make_pair(0, nums[0]));
        for(int i = 1; i < nums.size(); ++i){
            while(D.front().first < i-k){
                D.pop_front();
            }
            int score = nums[i]+D.front().second;
            while(!D.empty() && D.back().second <= score){
                D.pop_back();
            }
            D.emplace_back(make_pair(i, score));
        }
        return D.back().second;
    }
};
