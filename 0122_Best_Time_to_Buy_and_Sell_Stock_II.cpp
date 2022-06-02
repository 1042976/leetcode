class Solution {
public:
    //Time O(N), Space O(1)
    // int maxProfit(vector<int>& prices) {
    //     int l = 0, r = 1;
    //     int size = prices.size();
    //     int sum = 0;
    //     while(r < size){
    //         if(prices[r] <= prices[l]){
    //             l = r++;
    //         }else{
    //             if(r+1 == size || prices[r+1] < prices[r]){
    //                 sum += (prices[r]-prices[l]);
    //                 l = r+1;
    //                 r = l+1;
    //             }else{
    //                 ++r;
    //             }
    //         }
    //     }
    //     return sum;
    // }
    
    //Time O(N), Space O(1)
    int maxProfit(vector<int>& prices){
        int sum = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i-1] < prices[i]){
                sum += (prices[i]-prices[i-1]);
            }
        }
        return sum;
    }
};
