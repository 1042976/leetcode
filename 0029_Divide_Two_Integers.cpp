class Solution {
public:
    //Time O((logN)^2) Space O(1)
//     int divide(int dividend, int divisor) {
//         int sign = 1;
//         if(dividend < 0){
//             sign = -1;
//         }else{
//             dividend = -dividend;
//         }
//         if(divisor < 0){
//             sign = -sign;
//         }else{
//             divisor = -divisor;
//         }
//         if(divisor == -1 && dividend == INT_MIN){
//             return sign == 1? INT_MAX : INT_MIN;
//         }else if(dividend > divisor){
//             return 0;
//         }
//         int res = 0;
//         int b = 1;
//         int a = divisor;
//         while(true){
//             if(dividend > a){
//                 b = 1;
//                 a = divisor;
//             }
//             dividend -= a;
//             res += b;
//             if(dividend > divisor){
//                 break;
//             }
//             b <<= 1;
//             a += a;   
//         }
//         return sign == 1? res : -res;       
//     }
    
    //Time O(logN), Space O(1)
     int divide(int dividend, int divisor){
         int sign = 1;
         if(dividend < 0){
             sign = -1;
         }else{
             dividend = -dividend;
         }
         if(divisor < 0){
             sign = -sign;
         }else{
             divisor = -divisor;
         }
         if(dividend == INT_MIN && divisor == -1){
             return sign == 1? INT_MAX : INT_MIN;
         }
         int quotient = 0;
         int a = divisor;
         int k = 1;
         while(a >= dividend-a){
             a += a;
             k <<= 1;
         }
         while(dividend <= divisor){
             if(dividend > a){
                a >>= 1;
                k >>= 1;
             }else {
                dividend -= a; 
                quotient += k;
             }
         }
         return sign == 1? quotient : -quotient;
     }
};
