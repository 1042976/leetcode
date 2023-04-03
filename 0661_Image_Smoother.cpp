class Solution {
public:
    //Time O(N), Space O(1)
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        int offsets[8][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int sum = img[i][j]&0xFF;
                int count = 1;
                for(int k = 0; k < 8; ++k){
                    int nI = offsets[k][0]+i, nJ = offsets[k][1]+j;
                    if(nI >= 0 && nI < m && nJ >= 0 && nJ < n){
                        sum += img[nI][nJ]&0xFF; 
                        ++count;
                    }
                }
                img[i][j] += (sum/count)<<16;
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                img[i][j] >>= 16;
            }
        }
        return img;
    }
};
