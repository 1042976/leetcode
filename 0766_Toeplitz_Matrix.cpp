class Solution {
public:
    // bool check(vector<vector<int>>& matrix, int m, int n, int i, int j){
    //     while(i+1 < m && j+1 < n){
    //         if(matrix[i+1][j+1] != matrix[i][j]){
    //             return false;
    //         }
    //         ++i;
    //         ++j;
    //     }       
    //     return true;
    // }
    // //Time O(mn), Space O(1)
    // bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    //     int m = matrix.size(), n = matrix[0].size();
    //     for(int k = 0; k < m; ++k){
    //         int i = k;
    //         int j = 0;
    //         if(!check(matrix, m, n, i, j)){
    //             return false;
    //         }
    //     }
    //     for(int k = 1; k < n; ++k){
    //         int i = 0;
    //         int j = k;
    //         if(!check(matrix, m, n, i, j)){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    //Time O(mn), Space O(1)
    bool isToeplitzMatrix(vector<vector<int>>& matrix){
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i-1][j-1] != matrix[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};
