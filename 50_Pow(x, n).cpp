class Solution {
public:
    //Time O(logn) Space O(1)
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        x = n < 0? 1.0/x : x;
        double tmp = x, res = x;
        n = n < 0? abs(n+1) : n-1;
        int a = 1;
        while(n > 0){
            res *= tmp;
            n -= a;
            if(a <= (n>>1)){
                a *= 2;
                tmp *= tmp;
            }else{
                a = 1;
                tmp = x;
            }
        }
        return res;
        
    }
};
