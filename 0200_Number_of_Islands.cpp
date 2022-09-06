class Solution {
public:
    //dfs. T-O(mn), S-O(mn)
//     vector<pair<int, int>> offsets{make_pair(-1, 0), make_pair(1, 0), make_pair(0,1), make_pair(0,-1)};
//     int numIslands(vector<vector<char>>& grid) {
//         int counter = 0;
//         for(int i = 0; i < grid.size(); ++i){
//             for(int j = 0; j < grid[0].size(); ++j){
//                 if(grid[i][j] == '1'){
//                     ++counter;
//                     grid[i][j] = '2';
//                     markSurrounding(grid, i, j);
//                 }
//             }
//         }
//         return counter;
//     }
    
//     void markSurrounding(vector<vector<char>>& grid, int i, int j){
//         for(const auto &offset: offsets){
//             int ofi = i+offset.first;
//             int ofj = j+offset.second;
//             if(ofi < 0 || ofi >= grid.size() || ofj < 0 || ofj >= grid[0].size() || grid[ofi][ofj] == '2'){
//                 continue;
//             }
//             if(grid[ofi][ofj] == '1'){
//                 grid[ofi][ofj] = '2';
//                 markSurrounding(grid, ofi, ofj);
//             }
//         }
//     }
    //bfs. T-O(mn), S-O(min(m, n))
    // int numIslands(vector<vector<char>>& grid){
    //     int counter = 0;
    //     for(int i = 0; i < grid.size(); ++i){
    //         for(int j = 0; j < grid[0].size(); ++j){
    //             if(grid[i][j] == '1'){
    //                 ++counter;
    //                 grid[i][j] = '0';
    //                 queue<pair<int, int> > Q;
    //                 Q.emplace(make_pair(i, j));
    //                 while(!Q.empty()){
    //                     int curI = Q.front().first;
    //                     int curJ = Q.front().second;
    //                     Q.pop();
    //                     if(curI-1 >= 0 && grid[curI-1][curJ] == '1'){
    //                         grid[curI-1][curJ] = '0';
    //                         Q.emplace(make_pair(curI-1, curJ));
    //                     }
    //                     if(curI+1 < grid.size() && grid[curI+1][curJ] == '1'){
    //                         grid[curI+1][curJ] = '0';
    //                         Q.emplace(make_pair(curI+1, curJ));
    //                     }
    //                     if(curJ-1 >= 0 && grid[curI][curJ-1] == '1'){
    //                         grid[curI][curJ-1] = '0';
    //                         Q.emplace(make_pair(curI, curJ-1));
    //                     }
    //                     if(curJ+1 < grid[0].size() && grid[curI][curJ+1] == '1'){
    //                         grid[curI][curJ+1] = '0';
    //                         Q.emplace(make_pair(curI, curJ+1));
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     return counter;
    // }
    
    class DSU{
    private:
        int size;
        vector<int> parent, rank;
    public:
        DSU(int m, int n):size(m*n), parent(size), rank(size, 0){
            for(int i = 0; i < size; ++i){
                parent[i] = i;
            }
        }
        int find(int i){
            if(parent[i] != i){
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        
        bool Union(int i, int j){
            int x = find(i), y = find(j);
            if(x == y){
                return false;
            }else{
                if(rank[x] < rank[y]){
                    parent[x] = y;
                }else if(rank[x] > rank[y]){
                    parent[y] = x;
                }else{
                    parent[y] = x;
                    ++rank[x];
                }
                return true;
            }
        }
    };
    //Time O(N*a(N)), Space O(N), N is the total number of points in the grid
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size(), count = 0;
        DSU dsu(m, n);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++count; 
                    if(i > 0 && grid[i-1][j] == '1'){
                        if(dsu.Union((i-1)*n+j, i*n+j)){
                            --count;
                        }
                    }
                    if(j > 0 && grid[i][j-1] == '1'){
                        if(dsu.Union(i*n+j-1, i*n+j)){
                            --count;
                        }
                    }
                }
            }
        }   
        return count;
    }
};
