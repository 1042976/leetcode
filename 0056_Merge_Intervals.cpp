class Solution {
public:
    //T-O(nlogn) S-O(logn)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)->bool{
            return a[0] < b[0];
        });
        vector<vector<int> > res;
        if(intervals.empty()){
            return res;
        }
        res.emplace_back(intervals[0]);
        for(size_t i = 1; i < intervals.size(); ++i){
            int startCur = intervals[i][0];
            int endCur = intervals[i][1];
            vector<int> last = res.back();
            if(startCur > last[1]){
                res.emplace_back(intervals[i]);
            }else{
                int newEnd = endCur>last[1]? endCur : last[1];
                vector<int> merged{last[0], newEnd};
                res.pop_back();
                res.emplace_back(merged);
            }    
        }
        return res;
        
    }
};
