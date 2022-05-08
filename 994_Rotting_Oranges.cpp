class Solution {
public:
    //T-O(MN), S-O(MN), bfs
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        int numOfFresh = 0;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int> > Q;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 2){
                    Q.emplace(make_pair(i, j));
                }else if(grid[i][j] == 1){
                    ++numOfFresh;
                }
            }
        }
        int offsets[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!Q.empty()){
            if(numOfFresh == 0){
                break;
            }
            int sizeOfQueue = Q.size();
            ++minute;
            while(sizeOfQueue--){
                auto rotten = Q.front();
                Q.pop();
                for(const auto &offset : offsets){
                    int row = rotten.first + offset[0];
                    int col = rotten.second + offset[1];
                    if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1){
                        --numOfFresh;
                        grid[row][col] = 2;
                        Q.emplace(make_pair(row, col));
                    }
                }
            }
        }
        return numOfFresh == 0? minute : -1;
    }
};
