class Solution {
public:

//     bool intersect(vector<int> &r1, vector<int> &r2){
//         int i = 0, j = 0;
//         while(i < r1.size() && j < r2.size()){
//             if(r1[i] == r2[j]){
//                 return true;
//             }else if(r1[i] < r2[j]){
//                 ++i;
//             }else{
//                 ++j;
//             }
//         }
//         return false;
//     }
//     //Time O(n^2*m), Space O(n^2)
//     int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
//         if(source == target){
//             return 0;
//         }
//         //build graph
//         int numOfBuses = routes.size();
//         vector<vector<int> > adjList(numOfBuses);
//         queue<int> Q;
//         unordered_set<int> targetBuses;
//         unordered_set<int> visited;
//         for(auto &route : routes){
//             sort(route.begin(), route.end());
//         }
//         for(int i = 0; i < numOfBuses-1; ++i){
//             for(int j = i+1; j < numOfBuses; ++j){
//                 if(intersect(routes[i], routes[j])){
//                     adjList[i].emplace_back(j);
//                     adjList[j].emplace_back(i);
//                 }               
//             }
//         }
        
//         for(int i = 0; i < numOfBuses; ++i){
//             if(binary_search(routes[i].begin(), routes[i].end(), source)){
//                 visited.insert(i);
//                 Q.emplace(i);
//             }
//             if(binary_search(routes[i].begin(), routes[i].end(), target)){
//                 targetBuses.insert(i);
//             }
//         }
//         int depth = 0;
//         while(!Q.empty()){
//             int size = Q.size();
//             while(size--){
//                 int top = Q.front();
//                 Q.pop();
//                 if(targetBuses.count(top)){
//                     return depth+1;
//                 }else{
//                     for(const auto &adj : adjList[top]){
//                         if(visited.count(adj) == 0){
//                            Q.emplace(adj);
//                            visited.insert(adj);
//                         }
//                     }
//                 }
//             }
//             ++depth;
//         }
//         return -1;
//     }
  
    //Time O(NM), Space O(NM)
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target){
        unordered_map<int, vector<int> > hashMap;
        for(int i = 0; i < routes.size(); ++i){
            for(const auto &stop : routes[i]){
                hashMap[stop].emplace_back(i);
            }
        }
        unordered_set<int> visitedBuses;
        queue<int> Q;
        Q.emplace(source);
        int depth = 0;
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                int curStop = Q.front();
                Q.pop();
                if(curStop == target){
                    return depth;
                }
                for(const auto &bus : hashMap[curStop]){
                    if(visitedBuses.find(bus) == visitedBuses.end()){
                        for(const auto &stop : routes[bus]){
                                Q.emplace(stop);
                        }   
                        visitedBuses.insert(bus);
                    }
                }
            }
            ++depth;
        }
        return -1;
    }
};
