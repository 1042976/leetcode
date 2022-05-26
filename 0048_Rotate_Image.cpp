class Solution {
public:
    //Time O(n^2), Space O(1)
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for(int d = 0; d < n/2; ++d){
    //         for(int j = d; j < n-1-d; ++j){
    //             int i = d;
    //             int curValue = matrix[i][j];
    //             for(int k = 0; k < 4; ++k){
    //                 int nextI = j, nextJ = n-1-i;
    //                 int nextValue = matrix[nextI][nextJ];
    //                 matrix[nextI][nextJ] = curValue;
    //                 i = nextI;
    //                 j = nextJ;
    //                 curValue = nextValue;
    //             }
    //         }
    //     }
    // }
    
    //Time O(n^2), Space O(1)
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        //Transpose
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse
        for(int i = 0; i < n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};
