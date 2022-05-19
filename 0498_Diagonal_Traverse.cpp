class Solution {
public:
    //Time O(mn), Space O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int x = 0, y = 0;
        int offsetX = -1, offsetY = 1;
        while(x < m && y < n){
            res.emplace_back(mat[x][y]);
            int newX = x + offsetX;
            int newY = y + offsetY;
            if(newX == -1 || newY == -1 || newX == m || newY == n){
                int a = x+y;
                if(offsetY == 1){
                    a < n-1? ++y : ++x;
                }else{
                    a < m-1? ++x : ++y;
                }
                offsetX = -offsetX;
                offsetY = -offsetY;
            }else{
                x = newX;
                y = newY;
            }
        }
        return res;
    }
};
