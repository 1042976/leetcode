class Solution {
public:
    //Time O(mn), Space O(m+n)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size(), n = matrix[0].size();
    //     vector<bool> rows(m, false), columns(n, false);
    //     for(int i = 0; i < m; ++i){
    //         for(int j = 0; j < n; ++j){
    //             if(matrix[i][j] == 0){
    //                 rows[i] = true;
    //                 columns[j] = true;
    //             }
    //         }
    //     }
    //     for(int i = 0; i < m; ++i){
    //         for(int j = 0; j < n; ++j){
    //             if(rows[i] || columns[j]){
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }
    
    //Time O(MN), Space O(1)
    void setZeroes(vector<vector<int>>& matrix){
        int m = matrix.size(), n = matrix[0].size();
        bool firstColumn = false;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 0){
                firstColumn = true;
                break;
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j = 0; j < n; ++j){
                matrix[0][j] = 0;
            }
        }
        if(firstColumn){
            for(int i = 0; i < m; ++i){
                matrix[i][0] = 0;
            }
        }
    }
};
