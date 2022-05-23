class Solution {
public:
    //Time O(n), Space O(1)
    // int trap(vector<int>& height) {
    //     int size = height.size();
    //     int m = 0;
    //     for(int i = 1; i < size; ++i){
    //         if(height[i] > height[m]){
    //             m = i;
    //         }
    //     }
    //     int res = 0;
    //     int maxHeight = height[0];
    //     for(int i = 1; i < m; ++i){
    //         if(maxHeight > height[i]){
    //             res += maxHeight-height[i];
    //         }else{
    //             maxHeight = height[i];
    //         }
    //     }
    //     maxHeight = height.back();
    //     for(int i = size-2; i > m; --i){
    //         if(maxHeight > height[i]){
    //             res += maxHeight-height[i];
    //         }else{
    //             maxHeight = height[i];
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(n), Space O(1)
    int trap(vector<int>& height){
        int lM = 0, rM = 0;
        int l = 0, r = height.size()-1;
        int res = 0;
        while(l <= r){
            if(height[l] < height[r]){
                if(height[l] > lM){
                    lM = height[l];
                }else{
                    res += lM-height[l];
                }
                ++l;
            }else{
                if(height[r] > rM){
                    rM = height[r];
                }else{
                    res += rM-height[r];
                }
                --r;
            }
        }
        return res;
    }
};
