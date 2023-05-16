class Solution {
public:
    int I[8][2] = {{2,-1},{2,1},{-2,1},{-2,-1},{1,-2},{1,2},{-1,-2},{-1,2}};
    //BFS. Time O(|xy|), Space O(|xy|)
    // int minKnightMoves(int x, int y) {
    //     if(x < 0 || y < 0){
    //         return minKnightMoves(abs(x), abs(y));
    //     }
    //     bool memo[x+5][y+5];
    //     memset(memo, 0, sizeof(memo));
    //     queue<vector<int> > Q;
    //     Q.push({0,0});
    //     int level = 0;
    //     vector<int> pos(2), next(2);
    //     while(!Q.empty()){
    //         int size = Q.size();
    //         while(size--){
    //             pos = Q.front();
    //             Q.pop();
    //             if(pos[0] == x && pos[1] == y){
    //                 return level;
    //             }
    //             for(int i = 0; i < 8; ++i){
    //                 next[0] = pos[0]+I[i][0];
    //                 next[1] = pos[1]+I[i][1];
    //                 if(next[0] < -2 || next[0] > x+2 || next[1] < -2 || next[1] > y+2){
    //                     continue;
    //                 }
    //                 if(memo[next[0]+2][next[1]+2]){
    //                     continue;
    //                 }
    //                 memo[next[0]+2][next[1]+2] = true;
    //                 Q.emplace(next);
    //             }
    //         }
    //         ++level;
    //     }
    //     return -1;
    // }

    // DFS. Time O(|xy|), Space O(|xy|)
    vector<vector<int> > memo;
    int dfs(int x, int y){
        if(memo[x][y] != -1){
            return memo[x][y];
        }
        if(x == 0 && y == 0){
            return 0;
        }else if(x+y == 2){
            return 2;
        }else{
            memo[x][y] = min(dfs(abs(x-1), abs(y-2)), dfs(abs(x-2), abs(y-1)))+1;
            return memo[x][y];
        }
    }
    int minKnightMoves(int x, int y){
        memo.resize(abs(x)+3, vector<int>(abs(y)+3, -1));
        return dfs(abs(x), abs(y));
    }
};
