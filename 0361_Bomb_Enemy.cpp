class Solution {
public:
    // Time O(MN), Space O(N)
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int maxHits = 0;
        size_t rows = grid.size(), cols = grid[0].size();
        int rowHits = 0, colHits[cols];
        memset(colHits, 0, sizeof(colHits));
        for(size_t i = 0; i < rows; ++i){
            for(size_t j = 0; j < cols; ++j){
                if(i == 0 || grid[i-1][j] == 'W'){
                    colHits[j] = 0;
                    for(size_t k = i; k < rows; ++k){
                        if(grid[k][j] == 'E'){
                            ++colHits[j];
                        }else if(grid[k][j] == 'W'){
                            break;
                        }
                    }
                }
                if(j == 0 || grid[i][j-1] == 'W'){
                    rowHits = 0;
                    for(size_t k = j; k < cols; ++k){
                        if(grid[i][k] == 'E'){
                            ++rowHits;
                        }else if(grid[i][k] == 'W'){
                            break;
                        }
                    }
                }
                if(grid[i][j] == '0'){
                    maxHits = max(maxHits, rowHits+colHits[j]);
                }
            }
        }
        return maxHits;
    }
};
