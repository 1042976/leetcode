class Solution {
public:
    //Time O(n), Space O(1)
    // int maxProfit(vector<int>& prices) {
    //     int minPrice = INT_MAX, maxPrice = INT_MIN;
    //     int profit = 0;
    //     for(const auto &x : prices){
    //         if(x < minPrice){
    //             minPrice = x;
    //             maxPrice = x;
    //         }else if(x > maxPrice){
    //             maxPrice = x;
    //             profit = max(profit, maxPrice-minPrice);
    //         }
    //     }
    //     return profit;
    // }
    //Time O(n), Space O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int profit = 0;
        for(const auto &x : prices){
            if(x < minPrice){
                minPrice = x;
            }else{
                profit = max(profit, x-minPrice);
            }
        }
        return profit;
    }
};
