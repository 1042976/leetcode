class Solution {
public:
    //T-O(NlogN) S-O(N)  min_heap
    // int minMeetingRooms(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool{
    //         return a[0] < b[0];
    //     });
    //     priority_queue<int, vector<int>, std::greater<int> > meetings;
    //     for(const auto &interval : intervals){
    //         if(!meetings.empty() && meetings.top() <= interval[0]){
    //             meetings.pop();
    //         }
    //         meetings.emplace(interval[1]);
    //     }
    //     return meetings.size();
    // }
    
    //two pointers. T-O(NlogN), S-O(N)
    int minMeetingRooms(vector<vector<int>>& intervals){
        vector<int> starts;
        vector<int> ends;
        for(const auto &x : intervals){
            starts.emplace_back(x[0]);
            ends.emplace_back(x[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int counter = 1;
        int i = 1, j = 0;
        while(i < intervals.size()){
            if(starts[i] < ends[j]){
                ++counter;
            }else{
                ++j;
            }
            ++i;
        }
        return counter;
    }
};
