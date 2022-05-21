class Solution {
public:
    //bfs. Time O(n), Space O(n)
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
    //         return -1;
    //     }
    //     int shortest = INT_MAX;
    //     queue<vector<int> > Q;
    //     Q.emplace(vector<int>{0,0,1});
    //     grid[0][0] = -1;
    //     int offsets[8][2] = {{1,0}, {0,1}, {-1, 0}, {0,-1}, {1, 1}, {-1,-1}, {1, -1}, {-1, 1}};
    //     while(!Q.empty()){
    //         auto cur = Q.front();
    //         Q.pop();
    //         if(cur[0]==n-1 && cur[1] == n-1){
    //             shortest = min(shortest, cur[2]);
    //             continue;
    //         }
    //         if(cur[2] >= shortest){
    //             continue;
    //         }
    //         for(int i = 0; i < 8; ++i){
    //             vector<int> newPoint{cur[0]+offsets[i][0], cur[1]+offsets[i][1], cur[2]+1};
    //             if(newPoint[0] >= 0 && newPoint[0] < n && newPoint[1] >= 0 && newPoint[1] < n && grid[newPoint[0]][newPoint[1]] == 0){
    //                 grid[newPoint[0]][newPoint[1]] = -1;
    //                 Q.emplace(newPoint);
    //             }
    //         }
    //     }
    //     return shortest == INT_MAX? -1 : shortest;
    // }
    
    //A* approach.
    int getDistance(int i, int j, int m, int n){
        return max(m-i, n-j);
    }
    //T-O(n), S-O(n)
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]){
            return -1;
        }
        list<list<vector<int> > > lists(3);
        vector<vector<bool> >  visited(n, vector<bool>(n, false));
        int offsets[8][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        lists.front().emplace_back(vector<int>{0,0,1, 1+getDistance(0,0,n-1,n-1)});
        while(!lists.empty()){
            while(lists.front().empty()){
                lists.pop_front();
            }
            if(lists.empty()){
                break;
            }else{
                while(lists.size() < 3){
                    lists.emplace_back(list<vector<int> >());
                }
            }
            auto it = lists.begin();
            vector<int> cur = it->front();
            it->pop_front();
            if(visited[cur[0]][cur[1]]){
                continue;
            }
            visited[cur[0]][cur[1]] = true;
            if(cur[0] == n-1 && cur[1] == n-1){
                return cur[2];
            }
            for(int k = 0; k < 8; ++k){
                int newRow = cur[0]+offsets[k][0];
                int newColumn = cur[1]+offsets[k][1];
                if(newRow == -1 || newRow == n || newColumn == -1 || newColumn == n || grid[newRow][newColumn] == 1 || visited[newRow][newColumn]){
                    continue;
                }
                int newLenOfPath = cur[2]+1;
                int newDistance = newLenOfPath + getDistance(newRow, newColumn, n-1,n-1);
                vector<int> newNode{newRow,newColumn,newLenOfPath,newDistance};
                int idx = newDistance-cur[3];
                auto it1 = lists.begin();
                if(idx == 0){
                    it1->emplace_back(newNode);  
                }else if(idx == 1){
                    ++it1;
                    it1->emplace_back(newNode);
                }else{
                    auto it2 = (--lists.end());
                    it2->emplace_back(newNode);  
                }
            }
        }
        return -1;
    }
    // int getDistance(int i1, int j1, int i2, int j2){
    //     return max(i2-i1, j2-j1);
    // }
    //Time O(nlogn) Space O(n)
    // int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    //     int n = grid.size();
    //     if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
    //         return -1;
    //     }
    //     vector<vector<bool> > visited(n, vector<bool>(n, false)); 
    //     int offsets[8][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
    //     auto compare = [](const vector<int> &a, const vector<int> &b)->bool{
    //         return a[3] > b[3];
    //     };
    //     priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
    //     minHeap.emplace(vector<int>{0,0,1,1+getDistance(0,0,n-1,n-1)});
    //     while(!minHeap.empty()){
    //         vector<int> cur = minHeap.top();
    //         minHeap.pop();
    //         if(visited[cur[0]][cur[1]]){
    //             continue;
    //         }
    //         visited[cur[0]][cur[1]] = true;
    //         if(cur[0] == n-1 && cur[1] == n-1){
    //             return cur[2];
    //         }
    //         for(int i = 0; i < 8; ++i){
    //             int newRow = offsets[i][0]+cur[0];
    //             int newColumn = offsets[i][1]+cur[1];
    //             if(newRow < 0 || newRow == n || newColumn < 0 || newColumn == n || grid[newRow][newColumn] == 1 || visited[newRow][newColumn]){
    //                 continue;
    //             }
    //             int newLenOfPath = cur[2]+1;
    //             int newEstimated = newLenOfPath+getDistance(newRow, newColumn,n-1,n-1);
    //             minHeap.emplace(vector<int>{newRow,newColumn, newLenOfPath, newEstimated});
    //         }
    //     }
    //     return -1;
    // }
};
