/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    // Time O(N^2), Space O(N). N is the total number of working-time intervals.
    // vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    //     list<Interval> availables;
    //     availables.emplace_back(Interval(INT_MIN, INT_MAX));
    //     for(auto& intervals : schedule){
    //         for(auto& interval : intervals){
    //             auto it = availables.begin();
    //             int start = interval.start;
    //             int end = interval.end;
    //             while(it != availables.end()){
    //                 if(end <= it->start){
    //                     break;
    //                 }else if(start <= it->start && end < it->end){
    //                     it->start = end;
    //                     break;
    //                 }else if(start <= it->start && end >= it->end){
    //                     it = availables.erase(it);
    //                 }else if(start > it->start && end < it->end){
    //                     availables.insert(next(it), Interval(end, it->end));
    //                     it->end = start;
    //                     break;
    //                 }else if(start > it->start && start < it->end && end >= it->end){
    //                     it->end = start;
    //                     ++it;
    //                 }else if(start >= it->end){
    //                     ++it;
    //                 }
    //             }
    //         }
    //     }
    //     availables.pop_front();
    //     availables.pop_back();
    //     vector<Interval> res(availables.begin(), availables.end());
    //     return res; 
    // }

    // Time O(nlogk), Space O(k). n is the total number of intervals, while k is the number of employees.
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        auto compare = [&schedule](const auto& a, const auto& b){
            return schedule[a.first][a.second].start > schedule[b.first][b.second].start;
        };
        priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t> >, decltype(compare) > minHeap(compare);
        for(size_t i = 0; i < schedule.size(); ++i){
            minHeap.emplace(make_pair(i, 0));
        }
        int prev = schedule[minHeap.top().first][minHeap.top().second].start;
        while(!minHeap.empty()){
            auto point = minHeap.top();
            minHeap.pop();
            int cur = schedule[point.first][point.second].start;
            if(cur > prev){
                res.emplace_back(Interval(prev, cur));
            } 
            prev = max(prev, schedule[point.first][point.second].end);
            if(++point.second < schedule[point.first].size()){
                minHeap.emplace(make_pair(point.first, point.second));
            }
        }
        return res;
    }
};
