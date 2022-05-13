class Solution {
public:
    //Time O(n), Space O(1)
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxH = INT_MIN;
        for(int i = heights.size()-1; i >= 0; --i){
            if(heights[i] > maxH){
                res.emplace_back(i);
                maxH = heights[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
