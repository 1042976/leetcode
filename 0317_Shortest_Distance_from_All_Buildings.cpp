class Solution {
public:
    //T-O(M^2 * N^2), S-O(MN)
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int> > D(rows, vector<int>(cols, 0));
        int offsets[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentEmptyValue = 0;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int, int> > Q;
                    Q.emplace(make_pair(i, j));
                    int steps = 0;
                    while(!Q.empty()){
                        int sizeOfQueue = Q.size();
                        ++steps;
                        while(sizeOfQueue--){
                            auto cur = Q.front();
                            Q.pop();
                            for(const auto &offset : offsets){
                                int row = cur.first + offset[0];
                                int col = cur.second + offset[1];
                                if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == currentEmptyValue){
                                    D[row][col] += steps;
                                    --grid[row][col];
                                    Q.push(make_pair(row, col));
                                }
                            }
                        }
                    }
                    --currentEmptyValue;
                }
            }
        }
        int minDistance = INT_MAX;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == currentEmptyValue){
                    minDistance = min(D[i][j], minDistance);
                }
            }
        }
        return minDistance == INT_MAX? -1 : minDistance;
    }
};
