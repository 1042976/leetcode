class Solution {
public:
    //Time O(N^2), Space O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res(numRows);
        res[0] = vector<int>{1};
        for(int row = 2; row <= numRows; ++row){
            vector<int>& arr = res[row-1];
            arr.resize(row, 1);
            for(int i = 1; i <= row-2; ++i){
                arr[i] = res[row-2][i-1]+res[row-2][i];
            }
        } 
        return res;
    }
};
