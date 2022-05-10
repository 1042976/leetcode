class Solution {
public:
    //Time O(n). Space O(1)
    int minCost(string colors, vector<int>& neededTime) {
        int pre = 0, cur = 1;
        int res = 0;
        while(cur < colors.size()){
            if(colors[pre] == colors[cur]){
                if(neededTime[pre] <= neededTime[cur]){
                    res += neededTime[pre];
                    pre = cur;
                }else{
                    res += neededTime[cur];
                }
            }else{
                pre = cur;
            }
            ++cur;
        }
        return res;
    }
};
