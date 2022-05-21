class Solution {
public:
    //Time O(m+n), Space O(1)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int> > res;
        while(i < firstList.size() && j < secondList.size()){
            int l = max(firstList[i][0], secondList[j][0]);
            int r = min(firstList[i][1], secondList[j][1]);
            if(l <= r){
                res.emplace_back(vector<int>{l, r});
            }
            firstList[i][1] < secondList[j][1]? ++i : ++j;
        }
        return res;
    }
};
