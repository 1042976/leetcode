class Solution {
public:

//     vector<vector<int> > memo;
//     int m, n;
//     int backtrack(vector<vector<int> >& matrix, int i, int j){
//         if(memo[i][j] >= 0){
//             return memo[i][j];
//         }
//         int longestOfNeigbor = 0;
//         if(i >= 1 && matrix[i-1][j] > matrix[i][j]){
//             longestOfNeigbor = max(longestOfNeigbor, backtrack(matrix, i-1, j)); 
//         }
//         if(i < m-1 &&  matrix[i+1][j] > matrix[i][j]){
//             longestOfNeigbor = max(longestOfNeigbor , backtrack(matrix, i+1, j));
//         }
//         if(j >= 1 &&  matrix[i][j-1] > matrix[i][j]){
//             longestOfNeigbor = max(longestOfNeigbor, backtrack(matrix, i, j-1));
//         }
//         if(j < n-1 && matrix[i][j+1] > matrix[i][j]){
//             longestOfNeigbor = max(longestOfNeigbor, backtrack(matrix, i, j+1)); 
//         }
//         memo[i][j] = 1 + longestOfNeigbor;
//         return memo[i][j];
//     }
    
//     //Time O(MN), Space O(MN)
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//         int longest = 0;
//         m = matrix.size();
//         n = matrix[0].size();
//         memo = vector<vector<int> >(m, vector<int>(n, -1));
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 longest = max(longest, backtrack(matrix, i, j));
//             }
//         }
//         return longest;
//     }
    
    //Time O(MN), Space O(MN)
    int longestIncreasingPath(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > outdegrees(m, vector<int>(n, 0));
        queue<pair<int, int> > Q;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i-1 >= 0 && matrix[i-1][j] > matrix[i][j]){
                    ++outdegrees[i][j];
                }
                if(i+1 < m && matrix[i+1][j] > matrix[i][j]){
                    ++outdegrees[i][j];
                }
                if(j-1 >= 0 && matrix[i][j-1] > matrix[i][j]){
                    ++outdegrees[i][j];
                }
                if(j+1 < n && matrix[i][j+1] > matrix[i][j]){
                    ++outdegrees[i][j];
                }
                if(outdegrees[i][j] == 0){
                    Q.emplace(make_pair(i,j));
                }
            }
        }
        int level = 0;
        while(!Q.empty()){
            ++level;
            int size = Q.size();
            while(size--){
                auto [i, j] = Q.front();
                Q.pop();
                if(i-1 >= 0 && matrix[i-1][j] < matrix[i][j]){
                    if(--outdegrees[i-1][j] == 0){
                         Q.emplace(make_pair(i-1, j));
                    }
                }
                if(i+1 < m && matrix[i+1][j] < matrix[i][j]){
                    if(--outdegrees[i+1][j] == 0){
                         Q.emplace(make_pair(i+1, j));
                    }
                }
                if(j-1 >= 0 && matrix[i][j-1] < matrix[i][j]){
                    if(--outdegrees[i][j-1] == 0){
                         Q.emplace(make_pair(i, j-1));
                    }
                }
                if(j+1 < n && matrix[i][j+1] < matrix[i][j]){
                    if(--outdegrees[i][j+1] == 0){
                         Q.emplace(make_pair(i, j+1));
                    }
                }                
            }
        }
        return level;
    }
};
