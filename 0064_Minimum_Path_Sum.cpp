class Solution {
public:

    // Time-O(MN), Space-O(MN).
    // int minPathSum(vector<vector<int>>& grid) {
    //     int rows = grid.size();
    //     int cols = grid[0].size();
    //     int minSums[rows][cols];
    //     minSums[rows-1][cols-1] = grid[rows-1][cols-1];
    //     for(int i = rows-2; i >= 0; --i){
    //         minSums[i][cols-1] = minSums[i+1][cols-1] + grid[i][cols-1];
    //     }
    //     for(int j = cols-2; j >= 0; --j){
    //         minSums[rows-1][j] = minSums[rows-1][j+1] + grid[rows-1][j];
    //     }
    //     for(int i = rows-2; i >= 0; --i){
    //         for(int j = cols-2; j >= 0; --j){
    //             minSums[i][j] = grid[i][j] + min(minSums[i+1][j], minSums[i][j+1]);
    //         }
    //     }
    //     return minSums[0][0];
    // }

    // Time O(MN), Space O(M)
    // int minPathSum(vector<vector<int>>& grid) {
    //     int rows = grid.size();
    //     int cols = grid[0].size();
    //     int minSums[rows];
    //     memset(minSums, 0, sizeof(minSums));
    //     minSums[rows-1] = grid[rows-1][cols-1];
    //     for(int i = rows-2; i >= 0; --i){
    //         minSums[i] = minSums[i+1] + grid[i][cols-1];
    //     }

    //     for(int j = cols-2; j >= 0; --j){
    //         minSums[rows-1] += grid[rows-1][j];
    //         for(int i = rows-2; i >= 0; --i){
    //             minSums[i] = grid[i][j] + min(minSums[i+1], minSums[i]);
    //         }
    //     }
    //     return minSums[0];
    // }

    // Time O(MN), Space O(1)
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = rows-2; i >= 0; --i){
            grid[i][cols-1] += grid[i+1][cols-1];
        }
        for(int j = cols-2; j >= 0; --j){
            grid[rows-1][j] += grid[rows-1][j+1];
        }
        for(int i = rows-2; i >= 0; --i){
            for(int j = cols-2; j >= 0; --j){
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};
