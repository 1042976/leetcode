class Solution {
public:
    vector<int> getRowsWithOne(vector<vector<int> >& grid){
        vector<int> rows;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    rows.emplace_back(i);
                }
            }
        }
        return rows;
    }

    vector<int> getColsWithOne(vector<vector<int> >& grid){
        vector<int> cols;
        for(int j = 0; j < grid[0].size(); ++j){
            for(int i = 0; i < grid.size(); ++i){
                if(grid[i][j] == 1){
                    cols.emplace_back(j);
                }
            }
        }
        return cols;
    }
    // Time O(MN), Space O(MN).
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows = getRowsWithOne(grid);
        vector<int> cols = getColsWithOne(grid);
        int minD = 0;
        size_t i = 0, j = rows.size()-1;
        while(i < j){
            minD += rows[j] - rows[i] + cols[j] - cols[i];
            ++i;
            --j;
        }
        return minD;
    }
};
