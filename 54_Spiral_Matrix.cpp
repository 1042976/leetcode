class Solution {
public:
    //T-O(M*N), S-O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int right = matrix[0].size()-1, bottom = matrix.size()-1, left = 0, top = 0;
        int i = 0, j = 0;
        vector<int> res;      
        while(true){
            for(int i = left; i <= right; ++i){
                res.emplace_back(matrix[top][i]);
            }
            if(++top > bottom){
                break;
            }
            for(int i = top; i <= bottom; ++i){
                res.emplace_back(matrix[i][right]);
            }
            if(--right < left){
                break;
            }
            for(int i = right; i >= left; --i){
                res.emplace_back(matrix[bottom][i]);
            }
            if(--bottom < top){
                break;
            }
            for(int i = bottom; i >= top; --i){
                res.emplace_back(matrix[i][left]);
            }
            if(++left > right){
                break;
            }
        }
        return res;   
    }
};
