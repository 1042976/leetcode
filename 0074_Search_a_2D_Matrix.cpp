class Solution {
public:
    // Time O(log(m*n)), Space O(1)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int rows = matrix.size(), cols = matrix[0].size();
    //     if(target < matrix[0][0] || target > matrix[rows-1][cols-1]){
    //         return false;
    //     }
    //     int low = 0, up = rows;
    //     while(low < up){
    //         int mid = low + ((up-low)>>1);
    //         if(matrix[mid][0] == target){
    //             return true;
    //         }else if(matrix[mid][0] < target){
    //             low = mid+1;
    //         }else{
    //             up = mid;
    //         }
    //     }
    //     --low;
    //     int left = 0, right = cols-1;
    //     while(left <= right){
    //         int mid = left + ((right-left)>>1);
    //         if(matrix[low][mid] == target){
    //             return true;
    //         }else if(matrix[low][mid] < target){
    //             left = mid+1;
    //         }else{
    //             right = mid-1;
    //         }
    //     }
    //     return false;
    // }
    // Time O(log(m*n)), Space O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows*cols-1;
        while(left <= right){
            int mid = left + ((right-left)>>1);
            int curVal = matrix[mid/cols][mid%cols];
            if(curVal == target){
                return true;
            }else if(curVal < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};
