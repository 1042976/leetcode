class Solution {
public:
    //  int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    // //Time O(Nk), Space O(Nk)
    // int shortestPath(vector<vector<int>>& grid, int k) {
    //     int m = grid.size(), n = grid[0].size();
    //     int visited[m][n];
    //     for(int i = 0; i < m; ++i){
    //         for(int j = 0; j < n; ++j){
    //             visited[i][j] = k+1;
    //         }
    //     }
    //     queue<vector<int>> Q;
    //     Q.emplace(vector<int>(4,0));
    //     while(!Q.empty()){
    //         vector<int> cur = Q.front();
    //         Q.pop();
    //         int i = cur[0], j = cur[1], steps = cur[2], ob = cur[3];
    //         if(i == m-1 && j == n-1){
    //             return steps;
    //         }
    //         if(visited[i][j] <= ob){
    //             continue;
    //         }
    //         visited[i][j] = ob;
    //         ++steps;
    //         for(int k = 0; k < 4; ++k){
    //             int nextI = i+offsets[k][0];
    //             int nextJ = j+offsets[k][1];
    //             if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n){
    //                 Q.emplace(vector<int>{nextI, nextJ, steps, ob+grid[nextI][nextJ]});
    //             }
    //         }
    //     }
    //     return -1;
    // }
    
    int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};  
    //Time O(Nklog(Nk)), Space O(Nk)
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int visited[m][n];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                visited[i][j] = k+1;
            }
        }
        auto compare = [](const vector<int>& a, const vector<int>& b){
            return b[0]+b[1]+a[2] > a[0]+a[1]+b[2];
        };
        priority_queue<vector<int>, vector<vector<int> >, decltype(compare) > minHeap(compare);
        minHeap.emplace(vector<int>(4,0));
        while(!minHeap.empty()){
            vector<int> cur = minHeap.top();
            minHeap.pop();
            int i = cur[0], j = cur[1], steps = cur[2], ob = cur[3];
            if(i == m-1 && j == n-1){
                return steps;
            }
            if(visited[i][j] <= ob){
                continue;
            }
            visited[i][j] = ob;
            ++steps;
            for(int k = 0; k < 4; ++k){
                int nextI = i+offsets[k][0];
                int nextJ = j+offsets[k][1];
                if(nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n){
                    minHeap.emplace(vector<int>{nextI, nextJ, steps, ob+grid[nextI][nextJ]});
                }
            }
        }
        return -1;
    }
};
