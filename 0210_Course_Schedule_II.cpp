class Solution {
public:
    //Time O(V+E), Space O(V+E)
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         //build graph
//         unordered_map<int, vector<int> > adjList;
//         vector<int> inDegree(numCourses, 0);
//         for(const auto &x : prerequisites){
//             adjList[x[1]].emplace_back(x[0]);
//             ++inDegree[x[0]];
//         }
        
//         //get valid order of courses
//         queue<int> Q;
//         for(int i = 0; i < numCourses; ++i){
//             if(inDegree[i] == 0){
//                 Q.emplace(i);
//             }
//         }
//         vector<int> res;
//         while(!Q.empty()){
//             int course = Q.front();
//             Q.pop();
//             res.emplace_back(course);
//             for(const auto &x : adjList[course]){
//                 if(--inDegree[x] == 0){
//                     Q.emplace(x);
//                 }
//             }
//         }
//         return res.size() == numCourses? res : vector<int>();
//     }
    enum STATE{
        WHITE,
        GREY,
        BLACK
    };
    vector<int> res;
    unordered_map<int, vector<int> > adjList;
    vector<STATE> state;
    bool hasCycle = false;
    void dfs(int course){
        if(hasCycle || state[course] == BLACK){
            return;
        }
        if(state[course] == GREY){
            hasCycle = true;
            return;
        }
        state[course] = GREY;
        for(const auto &x : adjList[course]){
            dfs(x);
        }
        state[course] = BLACK;
        res.emplace_back(course);
    }
    //Time O(V+E), Space O(V+E)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        //build graph
        state = vector<STATE>(numCourses, WHITE);
        for(const auto &x : prerequisites){
            adjList[x[1]].emplace_back(x[0]);
        }
        
        //get valid order of courses
        for(int i = 0; i < numCourses; ++i){
            dfs(i);
        }
        if(hasCycle){
            return vector<int>();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
