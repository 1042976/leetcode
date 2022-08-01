class Solution {
public:
    //Time O(n+k), Space O(1)
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(const auto &interval : updates){
            res[interval[0]] += interval[2];
            if(interval[1] < length-1){
                res[interval[1]+1] -= interval[2];
            }
        }
        partial_sum(res.begin(), res.end(), res.begin());
        return res;
    }
};
