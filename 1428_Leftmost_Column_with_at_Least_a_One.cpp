/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    // bool hasOne(BinaryMatrix &binaryMatrix, int rows, int j){
    //     for(int i = 0; i < rows; ++i){
    //         if(binaryMatrix.get(i, j) == 1){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // //Time O(MlogN), Space O(1)
    // int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    //     int rows = binaryMatrix.dimensions()[0], cols = binaryMatrix.dimensions()[1];
    //     int left = 0, right = cols-1;
    //     while(left <= right){
    //         int mid = left + ((right-left)>>1);
    //         if(hasOne(binaryMatrix, rows, mid)){
    //             right = mid-1;
    //         }else{
    //             left = mid+1;
    //         }
    //     }
    //     return left == cols? -1 : left;
    // }
    
    //Time O(M+N), Space O(1)
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0], cols = binaryMatrix.dimensions()[1];
        int i = 0, j = cols-1;
        while(i < rows && j >= 0){
            if(binaryMatrix.get(i, j)){
                --j;
            }else{
                ++i;
            }
        }
        return j == cols-1? -1 : j+1;
    }
};
