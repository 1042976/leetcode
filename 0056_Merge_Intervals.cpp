class Solution {
public:
    //Time O(NlogN), Space O(1)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        res.emplace_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] > res.back()[1]){
                res.emplace_back(intervals[i]);
            }else{
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
        }
        return res;
    }
};
