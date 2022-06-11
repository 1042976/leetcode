class Solution {
public:
    //Time O(1), Space O(1)
    // int getSum(int a, int b) {
    //     int c = a ^ b, d = a | b;
    //     int k = 1;
    //     int res = 0;
    //     int carry = 0;
    //     while(k < 2048){
    //         if(c&k){
    //             if(carry == 0){
    //                 res |= k;
    //             }
    //         }else{
    //             if(d&k){
    //                 if(carry){
    //                     res |= k;
    //                 }else{
    //                     carry = 1;
    //                 }
    //             }else{
    //                 if(carry){
    //                     res |= k;
    //                     carry = 0;
    //                 }
    //             }
    //         }
    //         k <<= 1;
    //     }
    //     if(a < 0 && b < 0 || a < 0 && abs(a) > b || b < 0 && abs(b) > a){
    //         res |= INT_MIN;
    //         k = 1073741824;
    //         while((k & res) == 0){
    //             res |= k;
    //             k >>= 1;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(1), Space O(1)
    int getSum(int a, int b){
        while(b != 0){
            unsigned int c = a;
            a ^= b;
            b = ((b&c) << 1);
        }
        return a;
    }
    
};
