class Solution {
public:
    //Time O(n^2), Space O(n^2)
    int largestIsland(vector<vector<int>>& grid) {
        int maxSize = INT_MIN;
        int n = grid.size();
        vector<pair<int, int> > offsets{{1,0}, {-1, 0}, {0,1}, {0,-1}};
        vector<int> sizeOfIslands;
        int flag = -1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = flag;
                    int size = 0;
                    queue<pair<int, int> > Q;
                    Q.emplace(make_pair(i, j));
                    while(!Q.empty()){
                        auto [row, column] = Q.front();
                        Q.pop();
                        ++size;
                        for(const auto &offset : offsets){
                            int nextRow = row + offset.first;
                            int nextColumn = column + offset.second;
                            if(nextRow >= 0 && nextRow < n && nextColumn >= 0 && nextColumn < n &&                                              grid[nextRow][nextColumn] == 1){
                                grid[nextRow][nextColumn] = flag;
                                Q.emplace(make_pair(nextRow, nextColumn));
                            }
                        }
                    }
                    sizeOfIslands.emplace_back(size);
                    maxSize = max(size, maxSize);
                    --flag;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    int size = 1;
                    unordered_set<int> hashSet;
                    for(const auto &offset : offsets){
                        int newI = i + offset.first;
                        int newJ = j + offset.second;
                        if(newI >= 0 && newI < n && newJ >= 0 && newJ < n && grid[newI][newJ] != 0){
                            int flag = grid[newI][newJ];
                            if(hashSet.count(flag) == 0){
                                size += sizeOfIslands[-flag-1];
                                hashSet.insert(flag);
                            }
                        }
                    }
                    maxSize = max(size, maxSize);
                }      
            }
        }
        return maxSize;
    }
};
