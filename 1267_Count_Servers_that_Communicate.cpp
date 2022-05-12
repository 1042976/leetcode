class Solution {
public:
    //Time O(mn), Space O(m+n)
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), columns(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    ++rows[i];
                    ++columns[j];
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    if(rows[i] > 1 || columns[j] > 1){
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};
