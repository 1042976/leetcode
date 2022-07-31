class Solution {
public:
    //Time O(N^2), Space O(N^2)
    // int triangularSum(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int> > pascal(n, vector<int>(n, 1));
    //     for(int i = 2; i < n; ++i){
    //         for(int j = 1; j < i; ++j){
    //             pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j])%10;
    //         }
    //     }
    //     return inner_product(nums.begin(), nums.end(), pascal[n-1].begin(), 0)%10;
    // }
    
    //Time O(N^2), Space O(N^2)
    // int triangularSum(vector<int>& nums){
    //     int n = nums.size();
    //     int pascal[n][n];
    //     for(int i = 0; i < n; ++i){
    //         pascal[i][0] = 1;
    //         pascal[i][i] = 1;
    //     }
    //     for(int i = 2; i < n; ++i){
    //         for(int j = 1; j < i; ++j){
    //             pascal[i][j] = (pascal[i-1][j-1]+pascal[i-1][j])%10;
    //         }
    //     }
    //     int res = 0;
    //     for(int i = 0; i < n; ++i){
    //         res += pascal[n-1][i]*nums[i];
    //     }
    //     return res%10;
    // }
    
    // int triangularSum(vector<int>& nums){
    //     int mod = 10;
    //     long long freq = 1, res = nums[0], n = nums.size();
    //     for(int k = 1; k < n; ++k){
    //         freq = freq*(n-k)/k;
    //         res += freq*nums[k];
    //     }
    //     return res%10;
    // }
    
    //Time O(N), Space O(1)
//     int triangularSum(vector<int>& nums){    
//         int invM[10];
//         memset(invM, 0, sizeof(invM));
//         invM[1] = 1;
//         invM[3] = 7;
//         invM[7] = 3;
//         invM[9] = 9;
        
//         int two[4] = {6, 2, 4, 8};
        
//         int freq = 1, res = nums[0], n = nums.size();
//         int expTwo = 0, expFive = 0;
//         for(int k = 1; k < n; ++k){
//             int m = n-k, d = k;
//             while(m % 2 == 0){
//                 m >>= 1;
//                 ++expTwo;
//             }
//             while(d % 2 == 0){
//                 d >>= 1;
//                 --expTwo;
//             }
//             while(m % 5 == 0){
//                 m /= 5;
//                 ++expFive;
//             }
//             while(d % 5 == 0){
//                 d /= 5;
//                 --expFive;
//             }
//             freq = freq*m%10;
//             freq = freq*invM[d%10]%10;
//             if(expTwo == 0 || expFive == 0){
//                 int toAdd = freq;
//                 if(expTwo > 0){
//                     toAdd = freq * two[expTwo%4];
//                 }else if(expFive > 0){
//                     toAdd = freq * 5;
//                 }
//                 res = (res+toAdd*nums[k])%10;
//             }
//         }
//         return res;
//     }
};
