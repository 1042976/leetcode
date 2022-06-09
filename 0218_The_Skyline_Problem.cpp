class Solution {
public:
    //Time O(NlogN), Space O(N)
    // vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    //     map<int, vector<int> > pointsMap;
    //     map<int, int> heightsMap;
    //     vector<vector<int> > res;
    //     for(const auto &building : buildings){
    //         pointsMap[building[0]].emplace_back(building[2]);
    //         pointsMap[building[1]].emplace_back(-building[2]);
    //     }
    //     for(const auto &[point, arr] : pointsMap){
    //         for(const auto &height : arr){
    //             height > 0 ? ++heightsMap[height] : --heightsMap[-height];
    //             if(heightsMap[abs(height)] == 0){
    //                 heightsMap.erase(abs(height));
    //             }
    //         }  
    //         int highest = heightsMap.empty()? 0 : heightsMap.rbegin()->first;
    //         if(res.empty() || res.back()[1] != highest){
    //             res.emplace_back(vector<int>{point, highest});
    //         }
    //     } 
    //     return res;
    // }
    
    //Time O(NlogN), Space O(N)
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
        set<int> skylineStartPoints;
        for(const auto &building : buildings){
            skylineStartPoints.insert(building[0]);
            skylineStartPoints.insert(building[1]);
        }
        int i = 0;
        priority_queue<pair<int, int> > maxHeap;
        vector<vector<int> > res;
        for(const auto &start : skylineStartPoints){
            while(i < buildings.size() && buildings[i][0] <= start){
                maxHeap.emplace(make_pair(buildings[i][2], buildings[i][1]));
                ++i;
            }
            while(!maxHeap.empty() && maxHeap.top().second <= start){
                maxHeap.pop();
            }
            int curH = maxHeap.empty()? 0 : maxHeap.top().first;
            if(res.empty() || res.back()[1] != curH){
                res.emplace_back(vector<int>{start, curH});
            }
        }
        return res;
    }
};
