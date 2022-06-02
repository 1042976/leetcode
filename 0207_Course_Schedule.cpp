class Solution {
public:
    //Time O(N+A), Space O(N+A), N: number of nodes, A: number of arrows
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses, 0);
        unordered_map<int, vector<int> > adjList;
        for(const auto &arr : prerequisites){
            ++inDegrees[arr[0]];
            adjList[arr[1]].emplace_back(arr[0]);
        }
        
        queue<int> Q;
        for(int i = 0; i < numCourses; ++i){
            if(inDegrees[i] == 0){
                Q.emplace(i);
            }
        }
        
        while(!Q.empty()){
            int id = Q.front();
            Q.pop();
            for(auto &adj : adjList[id]){
                if(--inDegrees[adj] == 0){
                    Q.emplace(adj);
                }
            }
        }
        
        for(const auto &val : inDegrees){
            if(val > 0){
                return false;
            }
        }
        return true;
    }
};
