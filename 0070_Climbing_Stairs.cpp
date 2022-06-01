class Solution {
public:
    //Time O(n), Space O(1)
    // int climbStairs(int n) {
    //     int dp1 = 1, dp2 = 2;
    //     if(n == 1){
    //         return dp1;
    //     }else if(n == 2){
    //         return dp2;
    //     }
    //     for(int i = 0; i < n-2; ++i){
    //         int dp = dp1+dp2;
    //         dp1 = dp2;
    //         dp2 = dp;
    //     }
    //     return dp2;
    // }
    
    // void multiply(long long A[2][2], long long B[2][2]){
    //     long long C[2][2];
    //     for(int i = 0; i < 2; ++i){
    //         for(int j = 0; j < 2; ++j){
    //             C[i][j] = A[i][0]*B[0][j]+A[i][1]*B[1][j];
    //         }
    //     }
    //     for(int i = 0; i < 2; ++i){
    //         A[i][0] = C[i][0];
    //         A[i][1] = C[i][1];
    //     }
    // }
    // //Time O(logn), Space O(1)
    // int climbStairs(int n){
    //     long long Q[2][2] = {{1,1}, {1,0}};
    //     long long res[2][2] = {{1,0}, {0,1}};
    //     while(n){
    //         if(n & 1){
    //             multiply(res, Q);
    //         }
    //         n >>= 1;
    //         multiply(Q, Q);
    //     }
    //     return (int)res[0][0];
    // }
    //Time O(logn), Space O(1)
    int climbStairs(int n){
        double a = sqrt(5);
        double Fn = (pow((1+a)/2.0, n+1)-pow((1-a)/2.0, n+1))/a;
        return (int)Fn;
    }
};
