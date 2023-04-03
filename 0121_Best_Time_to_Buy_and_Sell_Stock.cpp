class Solution {
public:
    //Time O(N), Space O(1)
    int maxProfit(vector<int>& prices) {
        int maxDif = 0, minVal = prices[0];
        for(int i = 1; i < prices.size(); ++i){
            maxDif = max(maxDif, prices[i]-minVal);
            minVal = min(minVal, prices[i]);
        }
        return maxDif;
    }
};
