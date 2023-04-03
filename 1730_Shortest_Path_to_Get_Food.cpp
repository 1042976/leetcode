class Solution {
public:
    //bfs
    int m, n;
    int bfs(vector<vector<char>>& grid, int i, int j){
        queue<pair<int, int> > Q;
        Q.emplace(make_pair(i, j));
        int depth = 0;
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                i = Q.front().first;
                j = Q.front().second;
                if(grid[i][j] == '#'){
                    return depth;
                }
                Q.pop();
                if(grid[i][j] == 'X'){
                    continue;
                }
                grid[i][j] = 'X';
                int x = i-1, y = j;
                if(x >= 0){
                    Q.emplace(make_pair(x, y));
                }
                x = i+1;
                if(x < m){
                    Q.emplace(make_pair(x, y));
                }
                x = i;
                y = j-1;
                if(y >= 0){
                    Q.emplace(make_pair(x, y));
                }                
                y = j+1;
                if(y < n){
                    Q.emplace(make_pair(x, y));
                }
            }
            ++depth;
        }
        return -1;
    }
    //Time O(MN), Space O(min(M,N));
    int getFood(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '*'){
                    return bfs(grid, i, j);
                }
            }
        }
        return -1;
    }
    
//     int m, n;
//     int bfs(vector<vector<char>>& grid, int i, int j){
//         queue<vector<int> > Q;
//         Q.emplace(vector<int>{i, j, 0});
//         while(!Q.empty()){
//             vector<int> info = Q.front();
//             i = info[0];
//             j = info[1];
//             if(grid[i][j] == '#'){
//                 return info[2];
//             }
//             Q.pop();
//             if(grid[i][j] == 'X'){
//                 continue;
//             }
//             grid[i][j] = 'X';
//             int depth = info[2]+1;
//             int x = i-1, y = j;
//             if(x >= 0){
//                 Q.emplace(vector<int>{x, y, depth});
//             }
//             x = i+1;
//             if(x < m){
//                 Q.emplace(vector<int>{x, y, depth});
//             }
//             x = i, y = j-1;
//             if(y >= 0){
//                 Q.emplace(vector<int>{x, y, depth});
//             }
//             y = j+1;
//             if(y < n){
//                 Q.emplace(vector<int>{x, y, depth});
//             }
//         }
//         return -1;
//     }
        
//     //bfs Time O(MN), Space O(MN)
//     int getFood(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 if(grid[i][j] == '*'){
//                     return bfs(grid, i, j);
//                 }
//             }
//         }
//         return -1;
//     }
};
