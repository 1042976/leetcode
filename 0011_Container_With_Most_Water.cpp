class Solution {
public:
    //Time O(n), Space O(1)
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxV = 0;
        while(l < r){
            maxV = max(maxV, min(height[l], height[r])*(r-l));
            height[l] < height[r]? ++l : --r;
        }
        return maxV;
    }
};
