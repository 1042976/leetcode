class Solution {
public:
    // double fastPow(double x, long long n){
    //     double half = pow(x, n/2);
    //     if(n%2){
    //         return x*half*half;
    //     }else{
    //         return half*half;
    //     }
    // }
    // //Time O(logn), Space O(logn)
    // double myPow(double x, int n) {
    //     if(n < 0){
    //         long long m = n;
    //         return fastPow(1/x, -m);
    //     }else{
    //         return fastPow(x, n);
    //     }
    // }
    
    //Time O(logn), Space O(1)
    double myPow(double x, int n){
        long long m = n;
        if(m < 0){
            x = 1/x;
            m = -m;
        }
        long long i = m;
        double res = 1;
        while(i > 0){
            if(i%2){
                res *= x;
            }
            i >>= 1;
            x = x*x;
        }
        return res;
    }
};
